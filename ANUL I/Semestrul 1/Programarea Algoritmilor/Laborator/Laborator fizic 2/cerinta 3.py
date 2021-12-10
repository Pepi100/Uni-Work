with open("cuburi.txt", "r") as input:
    n = int( input.readline().strip() )
    lista = []
    for line in input.readlines():
        line = line.split()
        lista.append( (int (line[0]), line[1]) )

lista.sort(reverse=True)

with open("turn.txt", "w") as output:
    ultimul = ""
    total = 0
    for size, color in lista:
        if color == ultimul:
            continue
        output.write(f"{size} {color}\n")
        total += size
        ultimul = color
    output.write(f"Inaltimea totala: {total}")
