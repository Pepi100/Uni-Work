lista = [int(x) for x in input().split()]
suma = int(input())
d = {}
for x in lista:
    if x in d:
        d[x][0] += 1
    elif suma - x in d:
        d[suma - x][1] +=1
    else:
        d[x] = [1, 0]

k = 0
for x in d:
    if d[x][1] == 0:
        k += d[x][0]  * (d[x][0] - 1) // 2
    else:
        k += d[x][0] * d[x][0]

print(d[1])