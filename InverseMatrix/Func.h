#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

class Matrix;
void Gauss(Matrix M);
void File(Matrix M); 
void LUdecomposition(Matrix a, Matrix l, Matrix u, int n);
void SwapRows(Matrix M, int row1, int row2);
void LUP(Matrix A, Matrix C, Matrix P, Matrix X);