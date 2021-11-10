n = int(input("n = "))

sd = 0
num = 0
max = 0

for i in range(1, n + 1):
    accum = 0
    for a in range(1, i + 1):
        if (i % a == 0):
            accum += a        
    sd = accum
    if (max < sd):
        max = sd
        num = i
print("Максимальна сума дільників", max,"у числа", num)