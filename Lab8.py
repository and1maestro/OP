n = int(input("n = "))
a = [[0] * n for i in range(n)]

num = 1
m = 0
min = n ** 2 
a[n // 2][n // 2] = n ** 2

for v in range(n // 2):
    for i in range(n - m):
        a[v][i + v] = num
        num = num + 1
    for i in range(v + 1, n - v):
        a[i][-v - 1] = num
        num = num + 1
    for i in range(v + 1, n - v):
        a[-v - 1][- i - 1] =num
        num = num + 1
    for i in range(v + 1, n - v - 1):
        a[-i - 1][v]=num
        num = num + 1
    m = m + 2

for i in a:
    print(*i)

b = [a[0][0], a[0][n - 1], a[n - 1][n - 1], a[n - 1][0]]

for j in b:
    if j < min:
        min = j
print("Min corner element:", min)
