import random

class Matrix:

    def __init__(self, size1, size2):
        self.size1 = size1
        self.size2 = size2
        self.M = [[random.randint(0, 100) / 10 for i in range(size2)] for j in range(size1)]

    def increase(self, num):
        for i in range(self.size1):
            for j in range(self.size2):
                self.M[i][j] = self.M[i][j] + num

    def print(self):
        for i in range(self.size1):
            for j in range(self.size2):
                self.M[i][j] = round(self.M[i][j], 2)
        for i in self.M:
            print(*i)
        print()

    def avg(self):
        sum = 0
        avg_ = 0
        for i in range(self.size1):
            for j in range(self.size2):
                sum = sum + self.M[i][j]
        avg_ = sum / (self.size1 * self.size2)
        return avg_
        
class IMatrix(Matrix):
    def __init__(self, size1, size2):
        self.size1 = size1
        self.size2 = size2
        self.M = [[random.randint(0, 10) for i in range(size2)] for j in range(size1)]

class DMatrix(Matrix):
    def __init__(self, size1, size2):
        self.size1 = size1
        self.size2 = size2
        self.M = [[random.randint(0, 100) / 10 for i in range(size2)] for j in range(size1)]

m = int(input("Amount of each: "))
r = int(input("Rows: "))
c = int(input("Columns: "))
print()