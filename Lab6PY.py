def sum(n):
    sd = 0
    for i in range(1, n + 1):
        if (n % i == 0): 
            sd += i
    return(sd)

n = int(input("n = "))

for x in range(2, n):
    y = sum(x) - x
    if (sum(y)-y) == x and (sum(x)-x) == y and x != y and (y - x) > 0:
        print(x, "i", y, "- дружні числа")
