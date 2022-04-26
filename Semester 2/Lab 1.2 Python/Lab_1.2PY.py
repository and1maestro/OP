from Functions import *

file_1 = "file_1.txt"
file_2 = "file_2.txt"

n = int(input("Enter the number of books: "))

create_first_file(file_1, n)
print("\nFirst file:")
output_difference(file_1)

create_second_file(file_1, file_2)
print("\nSecond file:")
output_file(file_2)
print()