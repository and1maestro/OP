q = float(input("Введіть число q: "))
r = float(input("Введіть число r: "))
b = float(input("Введіть число b: "))
c = float(input("Введіть число c: "))
d = float(input("Введіть число d: "))
n = int(input("Введіть натуральне число n, що є більшим за 1: "))

if n < 2:
    print("Ви ввели неправильне число n.")
else:
    k = 2
    y = c
    z = d
    x = q * z + d * y + b
    if n == 2:
        x = q * d + r * c + b
        print(x)
    else:
        x = q * d + r * c + b
        y = d
        for k in range(2,n,1):
            z = x
            x = q * z + r * y + b
            k = k + 1
            y = z
        print(x)
