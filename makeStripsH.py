firstLED = 512
strips = [
        32,
        29,
        24,
        17,
        10,
        7,
        8,
        15,
        11,
        12,
        14,
        10,
        9
        ]

highest = 0
for x in strips:
    if highest < x:
        highest = x
base = ["SAFE_LED" for x in range(highest)]

output = "#define STRIP_MAX_SIZE {}\n".format(highest)
output += "#define STRIPS_NUM {}\n".format(len(strips))

output += "const uint16_t strips[{}][{}] = {{\n".format(len(strips),highest)

for x in strips:
    entry = list(base)
    for j in range(x):
        entry[j] = firstLED + j
    firstLED = firstLED + x
    output += "{"
    output += ",".join([ str(x) for x in entry])
    output += "},\n"
output += "};"
with open("./TeensyPromocion/strips.h","w") as f:
    f.write(output)
