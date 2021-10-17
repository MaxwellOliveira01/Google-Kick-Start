from random import randint as r
t = 5
print(t)
for j in range(t):
        
    n = r(1,10)
    k = r(1,100)

    print(n,k)

    s = []

    while len(s) < n:
        s.append(r(0,k//2))

    print(*s)
