import os, re
from PIL import Image
from resizeimage import resizeimage
from openpyxl import load_workbook

excel = load_workbook("./ArduinoPromocion/nombres.xlsx")['Hoja1']
nombres_excel = [x.value.lower().strip() for x in excel['A']]
nombres_faltan = list(nombres_excel)

reg = re.compile(r"([\w\s\.]*)\.jpg")

dir_files = os.listdir("./EspPromocion/assets/originales")
dir_files = [x for x in dir_files if reg.search(x) is not None]

nombres_archivos = [x.group(1).lower() for x in [reg.search(y) for y in sorted(dir_files)]]

for x in nombres_archivos:
    if x in nombres_faltan:
        nombres_faltan.pop(nombres_faltan.index(x))

print("Los siguientes nombres carecen de imagenes:")
for x in nombres_faltan:
    print(x)

length = len(dir_files)

nombres_file = ""
arduino_file = ""
index = 0
size = 250

with open("./TeensyPromocion/Nombres.h","w") as f, open("./TeensyPromocion/NombresArduino.h","w") as g:
    nombres_file += "const char Nombres[{}][12] = {{\n".format(length)
    arduino_file += "const uint8_t matriz_arduino[{}] = {{\n" .format(length)
    for i, x in enumerate(sorted(dir_files)):
        match = re.search(r"^([\w\s\.]*)\.jpg$",x)
        if match is not None:
            nombre = match.group(1)
            nombre = nombre.lower()
            nombre = "".join([nombre[0].upper(),nombre[1:]])
            nombres_file += "    \"{}\",  //{}\n".format(nombre,i)
            arduino_file += "    {}, //{}, {}\n".format(nombres_excel.index(nombres_archivos[i]),i,nombre)
            with open(''.join(['./EspPromocion/assets/originales/',x])) as imagen:
                with Image.open(imagen) as baseimage:
                    thumbnail = resizeimage.resize_thumbnail(baseimage,[size,size])
                    thumbnail.save("".join(["./EspPromocion/assets/fotos/",str(index),".jpg"]),format='JPEG',quality=30)
                    index += 1

    nombres_file += "};"
    arduino_file += "};"
    f.write(nombres_file)
    g.write(arduino_file)


