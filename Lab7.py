import random

n = int(input("Amount of days = "))
a = int(input("Distance = "))
b = int(input("Height of a tree = "))
k = int(input("Number of the day = "))

if a > b:
    print("Distance can't be more than height!")
else:
    m = [random.randint(0,1) for i in range(n + 1)]
    l = [random.randint(0,1) for i in range(k)]
    for i in range(k):
        if m[i] == 0:
            l[i] = 2
        elif m[i] == 1:
            l[i] = -1

    x = a + sum(l)
    if x > (b - 1):
        print("The snail is on the top of the tree!")
    elif x < 1:
        print("The snail is on the ground!")
    else:
        print("The snail is",x,"meters high!")

    for i in range(k):
        if l[i] == 2:
            l[i] = "Sunny"
        elif l[i] == -1:
            l[i] = "Cloudy"
    print(l)