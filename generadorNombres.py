import os, re
from PIL import Image
from resizeimage import resizeimage

dir_files = os.listdir("./EspPromocion/assets/originales")

nombres = [x for x in sorted(dir_files) if re.search(r"\.jpg$",x) is not None]

length = len(nombres)

string_file = ""
index = 0
size = 250

with open("./TeensyPromocion/Nombres.h","w") as f:
    string_file += "const char Nombres[{}][11] = {{\n".format(length)
    for i, x in enumerate(nombres):
        match = re.search(r"^([\w\s]*)\.jpg$",x)
        if match is not None:
            nombre = match.group(1)
            nombre = nombre.split(" ")[1]
            nombre = nombre.lower()
            nombre = "".join([nombre[0].upper(),nombre[1:]])
            string_file += "    \"{}\",  //{}\n".format(nombre,i)
            with open(''.join(['./EspPromocion/assets/originales/',x])) as imagen:
                with Image.open(imagen) as baseimage:
                    thumbnail = resizeimage.resize_thumbnail(baseimage,[size,size])
                    thumbnail.save("".join(["./EspPromocion/assets/fotos/",str(index),".jpg"]),format='JPEG',quality=30)
                    index += 1

    string_file += "};"
    f.write(string_file)


