p = int(input())
c = int(input())



rez = [0] * (c+1)


def afisare(k):
    for i in range(1, k):
        print(rez[i],end="")
    print("")

def btk(k,s):
    if s == c and rez[1] == rez[k-1]:
        afisare(k)
    else:
        if k == 1:
            for i in range(max(1, rez[k - 1] - p), min(9, c - s) + 1):
                rez[k] = i
                btk(k + 1, s + i)

        else:
            for i in range( max(1, rez[k-1]-p), min(9, rez[k-1]+p, c-s)+1 ):
                rez[k] = i
                btk(k+1, s+i)


btk(1,0)