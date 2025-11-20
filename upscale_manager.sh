#!/bin/bash

# ==========================================
# POKE-EMERALD ASSET MANAGER (LINUX)
# Fitur:
# 1. Upscale Pixel Art (Recursive)
# 2. Generate Asset CSV (Audit Width/Height)
# 3. Backup/Export Assets (Copy to External Folder)
# 4. Restore Assets (Upscaled OR Original Backup)
# ==========================================

APP_TITLE="Poke-Expansion Asset Manager"

# --- 1. CEK DEPENDENCIES ---
check_deps() {
    MISSING_DEPS=""
    if ! command -v convert &> /dev/null; then MISSING_DEPS+=" imagemagick"; fi
    if ! command -v zenity &> /dev/null; then MISSING_DEPS+=" zenity"; fi

    if [ -n "$MISSING_DEPS" ]; then
        if [ -x "$(command -v apt-get)" ]; then
            zenity --question --title="Dependency Missing" \
                   --text="Aplikasi membutuhkan:$MISSING_DEPS\n\nInstall sekarang?" 
            if [ $? -eq 0 ]; then
                pkexec apt-get install -y imagemagick zenity
            else
                exit 1
            fi
        else
            zenity --error --text="Harap install manual:$MISSING_DEPS"
            exit 1
        fi
    fi
}

# --- 2. FUNGSI: GENERATE CSV ---
generate_csv() {
    TARGET_DIR=$(zenity --file-selection --directory --title="Pilih Folder Proyek/Aset untuk Scan")
    if [ -z "$TARGET_DIR" ]; then return; fi

    SAVE_FILE=$(zenity --file-selection --save --confirm-overwrite --title="Simpan File CSV" --filename="asset_details.csv")
    if [ -z "$SAVE_FILE" ]; then return; fi

    FILES=$(find "$TARGET_DIR" -type f \( -iname "*.png" -o -iname "*.bmp" -o -iname "*.gif" -o -iname "*.jpg" -o -iname "*.jpeg" -o -iname "*.webp" \))
    TOTAL=$(echo "$FILES" | wc -l)

    if [ "$TOTAL" -eq 0 ]; then
        zenity --error --text="Tidak ditemukan gambar di folder tersebut."
        return
    fi

    echo "Asset Name,File Path,Width,Height" > "$SAVE_FILE"

    CURRENT=0
    (
        IFS=$'\n'
        for file in $FILES; do
            DIMENSIONS=$(identify -format "%w,%h" "$file" 2>/dev/null)
            
            if [ -n "$DIMENSIONS" ]; then
                WIDTH=$(echo "$DIMENSIONS" | cut -d',' -f1)
                HEIGHT=$(echo "$DIMENSIONS" | cut -d',' -f2)
                NAME=$(basename "$file")
                REL_PATH=$(realpath --relative-to="$PWD" "$file")
                
                echo "$NAME,$REL_PATH,$WIDTH,$HEIGHT" >> "$SAVE_FILE"
            fi

            CURRENT=$((CURRENT + 1))
            PERCENT=$((CURRENT * 100 / TOTAL))
            echo "$PERCENT"
            echo "# Scanning: $(basename "$file")"
        done
    ) | zenity --progress --title="Generating CSV..." --text="Memulai scan..." --percentage=0 --auto-close --width=400

    zenity --info --text="Selesai!\nData aset disimpan di:\n$SAVE_FILE"
}

# --- 3. FUNGSI: BACKUP ASSETS ---
backup_assets() {
    CSV_FILE=$(zenity --file-selection --title="Pilih File CSV (asset_details.csv)" --file-filter="*.csv")
    if [ -z "$CSV_FILE" ]; then return; fi

    DEFAULT_DEST="$HOME/Documents/Asset"
    mkdir -p "$DEFAULT_DEST" 
    
    DEST_DIR=$(zenity --file-selection --directory --title="Pilih Folder Tujuan Backup" --filename="$DEFAULT_DEST/")
    if [ -z "$DEST_DIR" ]; then return; fi

    TOTAL_LINES=$(wc -l < "$CSV_FILE")
    TOTAL_FILES=$((TOTAL_LINES - 1))

    if [ "$TOTAL_FILES" -le 0 ]; then
        zenity --error --text="File CSV kosong atau format salah."
        return
    fi

    COPIED=0
    SKIPPED=0
    CURRENT=0
    
    (
        while IFS=, read -r col1 col2 col3 col4; do
            if [[ "$col1" == "Asset Name" ]]; then continue; fi
            
            SRC_FILE=$(echo "$col2" | tr -d '\r' | tr -d '"')
            FULL_DEST_PATH="$DEST_DIR/$SRC_FILE"
            DEST_PARENT=$(dirname "$FULL_DEST_PATH")

            echo "# Mengcopy: $SRC_FILE"

            if [ -f "$SRC_FILE" ]; then
                mkdir -p "$DEST_PARENT"
                if cp -p "$SRC_FILE" "$FULL_DEST_PATH"; then
                    COPIED=$((COPIED + 1))
                else
                    SKIPPED=$((SKIPPED + 1))
                fi
            else
                SKIPPED=$((SKIPPED + 1))
            fi

            CURRENT=$((CURRENT + 1))
            PERCENT=$((CURRENT * 100 / TOTAL_FILES))
            echo "$PERCENT"

        done < "$CSV_FILE"
    ) | zenity --progress --title="Backing Up Assets..." --percentage=0 --auto-close --width=400

    zenity --info --title="Backup Summary" \
        --text="Proses Selesai!\n\nBerhasil disalin: $COPIED file\nGagal/Tidak ditemukan: $SKIPPED file\n\nLokasi Backup:\n$DEST_DIR"
}

# --- 4. FUNGSI: RESTORE ASSETS (UPSCALED OR ORIGINAL) ---
restore_assets() {
    # A. Pilih CSV
    CSV_FILE=$(zenity --file-selection --title="Pilih File CSV (asset_details.csv)" --file-filter="*.csv")
    if [ -z "$CSV_FILE" ]; then return; fi

    # B. Pilih Tipe Restore (Upscaled vs Original/Backup)
    RESTORE_TYPE=$(zenity --list --radiolist --title="Pilih Sumber Restore" --text="Apa yang ingin Anda restore?" \
        --column="Pilih" --column="Tipe" --column="Keterangan" \
        TRUE "Upscaled Folder" "Restore hasil upscale (Folder Otomatis)" \
        FALSE "Original / Backup" "Restore file asli (Pilih Folder Manual)" \
        --height=250 --width=500)
    
    if [ -z "$RESTORE_TYPE" ]; then return; fi

    HOME_ASSETS_DIR="$HOME/Documents/Asset"
    SRC_ROOT_DIR=""

    if [ "$RESTORE_TYPE" == "Upscaled Folder" ]; then
        # -- Logic Lama: Upscaled --
        SCALE=$(zenity --list --radiolist --title="Restore Config" --text="Pilih Skala Folder Sumber:" --column="Pilih" --column="Skala" \
            FALSE "1" TRUE "2" FALSE "4" FALSE "8" --height=250)
        if [ -z "$SCALE" ]; then return; fi

        MODE_LABEL=$(zenity --list --radiolist --title="Restore Config" --text="Pilih Mode Folder Sumber:" --column="Pilih" --column="Metode" \
            TRUE "Sharp" FALSE "Smooth" FALSE "Outline" FALSE "Anime" --height=300)
        if [ -z "$MODE_LABEL" ]; then return; fi

        DIR_NAME="graphics_Upscaled_${SCALE}x_${MODE_LABEL}"
        SRC_ROOT_DIR="$HOME_ASSETS_DIR/$DIR_NAME"
        
    else
        # -- Logic Baru: Original / Backup --
        # Default path sesuai request: ~/Documents/Asset/graphics
        DEFAULT_BACKUP_PATH="$HOME_ASSETS_DIR/graphics"
        mkdir -p "$DEFAULT_BACKUP_PATH"
        
        SRC_ROOT_DIR=$(zenity --file-selection --directory --title="Pilih Folder Sumber Backup (Original)" --filename="$DEFAULT_BACKUP_PATH/")
        if [ -z "$SRC_ROOT_DIR" ]; then return; fi
    fi

    # Konfirmasi user
    zenity --question --title="Konfirmasi Restore" \
        --text="SUMBER: $SRC_ROOT_DIR\nTUJUAN: Folder Project Saat Ini\n\nFile yang ada di project akan DITIMPA.\nLanjutkan?"
    if [ $? -eq 1 ]; then return; fi

    if [ ! -d "$SRC_ROOT_DIR" ]; then
        zenity --error --text="Folder Sumber tidak ditemukan:\n$SRC_ROOT_DIR"
        return
    fi

    TOTAL_LINES=$(wc -l < "$CSV_FILE")
    TOTAL_FILES=$((TOTAL_LINES - 1))

    RESTORED=0
    SKIPPED=0
    CURRENT=0

    (
        while IFS=, read -r col1 col2 col3 col4; do
            if [[ "$col1" == "Asset Name" ]]; then continue; fi
            
            # Path Relatif Asli (Target di project)
            REL_PATH=$(echo "$col2" | tr -d '\r' | tr -d '"')
            DEST_PATH="$REL_PATH"
            
            # Mencari Source File (Logika Smart Fallback)
            # 1. Coba Full Path: SourceFolder/graphics/pokemon/img.png
            SRC_FILE="$SRC_ROOT_DIR/$REL_PATH"
            FOUND=false
            
            if [ -f "$SRC_FILE" ]; then
                FOUND=true
            else
                # 2. Smart Fallback: Hapus folder pertama dari path
                # Berguna jika SourceFolder adalah 'graphics' itu sendiri
                # Cek: SourceFolder/pokemon/img.png (tanpa 'graphics/')
                if [[ "$REL_PATH" == */* ]]; then
                    SHORT_PATH="${REL_PATH#*/}" # Hapus string sebelum slash pertama
                    ALT_SRC_FILE="$SRC_ROOT_DIR/$SHORT_PATH"
                    if [ -f "$ALT_SRC_FILE" ]; then
                        SRC_FILE="$ALT_SRC_FILE"
                        FOUND=true
                    fi
                fi
            fi

            echo "# Restoring: $REL_PATH"

            if [ "$FOUND" = true ]; then
                mkdir -p "$(dirname "$DEST_PATH")"
                # Copy dan timpa (-f)
                if cp -f "$SRC_FILE" "$DEST_PATH"; then
                    RESTORED=$((RESTORED + 1))
                else
                    SKIPPED=$((SKIPPED + 1))
                fi
            else
                SKIPPED=$((SKIPPED + 1))
            fi

            CURRENT=$((CURRENT + 1))
            PERCENT=$((CURRENT * 100 / TOTAL_FILES))
            echo "$PERCENT"

        done < "$CSV_FILE"
    ) | zenity --progress --title="Restoring Assets..." --percentage=0 --auto-close --width=400

    zenity --info --text="Restorasi Selesai!\n\nSumber: $SRC_ROOT_DIR\nBerhasil Restore: $RESTORED file\nGagal/Tidak Ditemukan: $SKIPPED file"
}

# --- 5. FUNGSI: UPSCALE IMAGES ---
upscale_images() {
    INPUT_DIR=$(zenity --file-selection --directory --title="Pilih Folder ROOT (Input)")
    if [ -z "$INPUT_DIR" ]; then return; fi

    SCALE=$(zenity --list --radiolist --title="$APP_TITLE" --text="Pilih Ukuran (Scale):" --column="Pilih" --column="Skala" \
        FALSE "1" TRUE "2" FALSE "4" FALSE "8" --height=250)
    if [ -z "$SCALE" ]; then return; fi

    MODE_LABEL=$(zenity --list --radiolist --title="$APP_TITLE" --text="Pilih Metode Upscaling:" --column="Pilih" --column="Metode" --column="Deskripsi" \
        TRUE "Sharp" "Nearest Neighbor (Tajam)" \
        FALSE "Smooth" "Smart Smoothing (Halus)" \
        FALSE "Outline" "Tambah Garis Tepi Hitam" \
        FALSE "Anime" "Gaya Anime (Clean)" \
        --height=300 --width=500)
    if [ -z "$MODE_LABEL" ]; then return; fi

    MODE=$(echo "$MODE_LABEL" | tr '[:upper:]' '[:lower:]')

    PARENT_DIR=$(dirname "$INPUT_DIR")
    BASE_NAME=$(basename "$INPUT_DIR")
    OUTPUT_ROOT="${PARENT_DIR}/${BASE_NAME}_Upscaled_${SCALE}x_${MODE_LABEL}"
    mkdir -p "$OUTPUT_ROOT"

    FILES=$(find "$INPUT_DIR" -type f \( -iname "*.png" -o -iname "*.jpg" -o -iname "*.jpeg" -o -iname "*.bmp" \))
    TOTAL_FILES=$(echo "$FILES" | wc -l)

    if [ "$TOTAL_FILES" -eq 0 ]; then
        zenity --warning --text="Tidak ada gambar ditemukan!"
        return
    fi

    CURRENT=0
    (
        IFS=$'\n'
        for file in $FILES; do
            REL_PATH="${file#$INPUT_DIR}"
            DEST_FILE="${OUTPUT_ROOT}${REL_PATH}"
            mkdir -p "$(dirname "$DEST_FILE")"
            
            echo "# Upscaling: $REL_PATH"

            if [[ "$MODE" == "sharp" ]]; then
                convert "$file" -scale "${SCALE}00%" "$DEST_FILE"
            elif [[ "$MODE" == "smooth" ]]; then
                super_scale=$((SCALE * 400))
                convert "$file" -scale "${super_scale}%" -resize "25%" -unsharp 0x1 -modulate 100,105 "$DEST_FILE"
            elif [[ "$MODE" == "outline" ]]; then
                convert "$file" -bordercolor none -border 1 \( +clone -channel A -morphology Dilate Disk:1 +channel -fill black -colorize 100 \) +swap -composite -scale "${SCALE}00%" "$DEST_FILE"
            elif [[ "$MODE" == "anime" ]]; then
                super_scale=$((SCALE * 400))
                convert "$file" -scale "${super_scale}%" -despeckle -median 2 -resize "25%" -modulate 100,125 -unsharp 0x0.75+0.75+0.008 "$DEST_FILE"
            fi

            CURRENT=$((CURRENT + 1))
            PERCENT=$((CURRENT * 100 / TOTAL_FILES))
            echo "$PERCENT"
        done
    ) | zenity --progress --title="Upscaling..." --percentage=0 --auto-close --width=500

    zenity --info --text="Selesai!\nOutput folder:\n$OUTPUT_ROOT"
}

# --- 6. MAIN LOOP ---
check_deps

while true; do
    ACTION=$(zenity --list --radiolist \
        --title="$APP_TITLE" \
        --text="Silakan pilih tugas:" \
        --column="Pilih" --column="Aksi" --column="Deskripsi" \
        TRUE "Upscale" "Upscale Folder (Batch)" \
        FALSE "Generate CSV" "Buat CSV dari Folder (Audit)" \
        FALSE "Backup Assets" "Export File ke ~/Documents/Asset" \
        FALSE "Restore Assets" "Import File (Upscaled/Original)" \
        --height=360 --width=550)

    if [ -z "$ACTION" ]; then break; fi

    if [ "$ACTION" == "Upscale" ]; then
        upscale_images
    elif [ "$ACTION" == "Generate CSV" ]; then
        generate_csv
    elif [ "$ACTION" == "Backup Assets" ]; then
        backup_assets
    elif [ "$ACTION" == "Restore Assets" ]; then
        restore_assets
    fi
    
    zenity --question --text="Kembali ke menu utama?" --ok-label="Ya" --cancel-label="Keluar"
    if [ $? -eq 1 ]; then break; fi
done
