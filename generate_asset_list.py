import os
import csv
from PIL import Image

def find_image_assets(directory="graphics", output_csv="asset_details.csv"):
    image_extensions = [".png", ".bmp", ".gif", ".jpg", ".jpeg", ".webp", ".svg"]
    assets_data = []

    # Add CSV header
    assets_data.append({"Asset Name": "Asset Name", "File Path": "File Path", "Width": "Width", "Height": "Height"})

    for root, _, files in os.walk(directory):
        for file in files:
            if any(file.lower().endswith(ext) for ext in image_extensions):
                asset_name = os.path.basename(file)
                file_path = os.path.join(root, file)
                width = ""
                height = ""
                try:
                    with Image.open(file_path) as img:
                        width, height = img.size
                except Exception as e:
                    print(f"Could not read dimensions for {file_path}: {e}")
                    
                assets_data.append({"Asset Name": asset_name, "File Path": file_path, "Width": width, "Height": height})

    with open(output_csv, 'w', newline='', encoding='utf-8') as csvfile:
        fieldnames = ["Asset Name", "File Path", "Width", "Height"]
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(assets_data[1:]) # Skip the manual header row and write from the second row

    print(f"Asset details written to {output_csv}")

if __name__ == "__main__":
    find_image_assets()