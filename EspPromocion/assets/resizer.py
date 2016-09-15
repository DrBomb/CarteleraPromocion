import os, re, json
from PIL import Image
from resizeimage import resizeimage

size = 250

files = os.listdir('./originales')
names = []
index = 0
for image in files:
    if re.search(r'\.jpg$',image) is not None:
        
        with open(''.join(['./originales/',image])) as f:
            with Image.open(f) as baseimage:
                thumbnail = resizeimage.resize_thumbnail(baseimage,[size,size])
                thumbnail.save("".join(["./fotos/",str(index),".jpg"]),format='JPEG',quality=30)
                index += 1
