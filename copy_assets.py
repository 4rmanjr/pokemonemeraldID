import os
import csv
import shutil

def copy_asset_files(csv_file="asset_details.csv", destination_dir=os.path.expanduser("~/Documents/Asset/")):
    # Ensure the destination directory exists
    os.makedirs(destination_dir, exist_ok=True)
    print(f"Ensured destination directory exists: {destination_dir}")

    copied_count = 0
    skipped_count = 0
    errors = []

    with open(csv_file, 'r', newline='', encoding='utf-8') as infile:
        reader = csv.DictReader(infile)
        for row in reader:
            source_path = row["File Path"] # This is expected to be relative to the script's execution dir
            
            # Construct the full destination path, including subdirectories
            # This will join destination_dir with the relative source_path
            destination_full_path = os.path.join(destination_dir, source_path)
            
            # Ensure the subdirectory for the destination file exists
            os.makedirs(os.path.dirname(destination_full_path), exist_ok=True)

            if os.path.exists(source_path):
                try:
                    shutil.copy2(source_path, destination_full_path)
                    copied_count += 1
                except Exception as e:
                    errors.append(f"Error copying {source_path} to {destination_full_path}: {e}")
                    skipped_count += 1
            else:
                errors.append(f"Source file not found: {source_path}")
                skipped_count += 1
    
    print(f"\n--- Copy Summary ---")
    print(f"Successfully copied {copied_count} files.")
    if skipped_count > 0:
        print(f"Skipped {skipped_count} files due to errors or not found.")
        print(f"Errors encountered:")
        for error in errors:
            print(f"- {error}")

if __name__ == "__main__":
    copy_asset_files()
