x = float(input ("Введіть значення х= "))
y = float(input("Введіть значення у= "))

if x>=-3 and x<=3 and y>=-3 and y<=3:
   if x ** 2+y ** 2 >=9: 
      if x<0 and y>0:
       print ("Не належить")
      else:
       print ("Належить")
   else:
        print ("Не належить")
else:
    print ("Не належить")
        

  
