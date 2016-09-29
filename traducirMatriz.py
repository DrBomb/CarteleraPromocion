from openpyxl import load_workbook
import os

wb = load_workbook("./ArduinoPromocion/nombres.xlsx")

sheet = wb['Hoja1']
numnombres = len(sheet["A"])

salida = "const uint8_t matriz_arduino[{}] = {{\n".format(numnombres)

for x in sheet['A']:
    print("Inserte numero para {}:".format(x.value))
    while True:
        try:
            numero = int(raw_input())
            break
        except KeyboardInterrupt:
            print("Cancelado")
            raise
        except:
            print("Inserte numero valido para {}:".format(x))
    salida += "{},\n".format(numero)
salida += "};"

with open("./TeensyPromocion/NombresArduino.h","w") as f:
    f.write(salida)
