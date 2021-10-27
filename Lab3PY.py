import math

x = float(input ("Введіть значення х = "))

if x < 0 or x > 2:
  print("Invalid x")
else: n = 0
t = ((n + 1) * x ** 2 - 1)/(math.factorial(1 + (2 ** n)))
S = t
while (t>10 ** (-5)): 
    n = n + 1
    S = S + t
else: print(S)
