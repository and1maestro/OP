n = int(input("Amount of days = "))
m = list()
print("Type in \"sunny\" or \"cloudy\"")
for i in range(n):
     m.append(input("Day "+str(i + 1)+" was "))

a = int(input("Distance = "))
b = int(input("Height of a tree = "))
k = int(input("Number of the day = "))
x = 0

if a > b:
    print("Distance can't be more than height!")
else:
    for i in range(k):
        if m[i] == "sunny":
            x = x + 2
        else:
            x = x - 1

    if x + a > (b - 1):
        print("The snail was on the top of the tree!")
    elif x + a < 1:
        print("The snail was on the ground!")
    else:
        print("The snail was",x + a,"meters high!")