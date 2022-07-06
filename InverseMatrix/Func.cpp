#include "Class.h"
#include "Func.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

// LU matrix decomposition
void LUdecomposition(Matrix a, Matrix l, Matrix u, int size)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (j < i)
                l.SetElement(j,i, 0);
            else {
                l.SetElement(j,i, a.GetElement(j,i));
                for (k = 0; k < i; k++) {
                    l.SetElement(j,i,  l.GetElement(j,i) - l.GetElement(j,k) * u.GetElement(k,i));
                }
            }
        }
        for (j = 0; j < size; j++) {
            if (j < i)
                u.SetElement(i, j, 0);
            else if (j == i)
                u.SetElement(i, j, 1);
            else 
            { 
                {
                    u.SetElement(i, j, a.GetElement(i, j) / l.GetElement(i, i));
                    for (k = 0; k < i; k++) {
                        u.SetElement(i, j, u.GetElement(i, j) - ((l.GetElement(i, k) * u.GetElement(k, j)) / l.GetElement(i, i)));
                    }
                }
            }
        }
    }
}

// Matrix row swapping
void SwapRows(Matrix M, int row1, int row2)
{
    float* temp = M.GetRow(row2);
    M.SetRow(row2, M.GetRow(row1));
    M.SetRow(row1, temp);
}

void LUP(Matrix A, Matrix P) 
{
    int size = A.GetSize();

    for (int i = 0; i < size; i++)
    {
        P.SetElement(i, i, 1);
    }

    for (int i = 0; i < size; i++) {
        float pivotValue = 0;
        int pivot = -1;
        for (int row = i; row < size; row++) {
            if (fabs(A.GetElement(row, i)) > pivotValue) {
                pivotValue = fabs(A.GetElement(row, i));
                pivot = row;
            }
        }
        if (pivotValue != 0) {
            SwapRows(P, pivot, i);
            SwapRows(A, pivot, i);
        }
    }
}

void Gauss(Matrix M)
{
    // Size of the matrix
    int size = M.GetSize();

    // Ratio of I[i][j] to Matrix[i][j]
    float ratio;

    int s = size * 2;
    float** I = new float* [s];
    for (int i = 0; i < s; i++)
    {
        I[i] = new float[s] {};
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            I[i][j] = M.GetElement(i, j);
        }
    }

    // Filling the main diagonal with 1's
    for (int i = 0; i < size; i++)
    {
        I[i][i + size] = 1;
    }

    for (int i = 0; i < size; i++)
    {
        // Checking if the main diagonal element is equal to zero
        if (I[i][i] == 0.0)
        {
            MessageBox::Show("One of the main diagonal elements is equal to zero!", "Mathematical Error");
        }
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                ratio = I[j][i] / I[i][i];
                for (int k = 0; k < 2 * size; k++)
                {
                    I[j][k] = I[j][k] - ratio * I[i][k];
                }
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = size; j < 2 * size; j++)
        {
            I[i][j] = I[i][j] / I[i][i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = size; j < size * 2; j++)
        {
            M.SetElement(i, j - size, I[i][j]);
        }
    }
}

// Writing the result to file
void File(Matrix M)
{
    int size = M.GetSize();
    std::ofstream fout;
    fout.open("File.txt");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fout << M.GetElement(i, j) << " ";
        }
        fout << "\n";
    }
    fout.close();
}

double determinant(Matrix matrix1, int n)
{
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n] {};
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = matrix1.GetElement(i, j);
        }
    }
    int det = 0;
    Matrix submatrix(10);
    submatrix.Zero();
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix.SetElement(subi, subj, matrix[i][j]);
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}