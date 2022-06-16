from Matrix import *

matrices = [Matrix(r,c) for i in range(2 * m)]

print("Int matrices:\n")
for i in range(m):
    matrices[i] = IMatrix(r, c)
    matrices[i].print()
    matrices[i].increase(9)

print("Double matrices:\n")
for i in range(m, 2 * m):  
    matrices[i] = DMatrix(r, c)
    matrices[i].print()
    matrices[i].increase(-5)

print("Changed matrices:\n")
print("Int matrices:\n")
for i in range(m):
    matrices[i].print()

print("Double matrices:\n")
for i in range(m, 2 * m):
    matrices[i].print()

min = matrices[0].avg()
min_ = 1

for i in range(2 * m):
    if matrices[i].avg() < min:
        min = matrices[i].avg()
        min_ = i + 1

print("The smallest average:", round(min, 2), "has matrix", min_, "\n")