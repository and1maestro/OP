#include "Class.h"
#include "Func.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

// LU matrix decomposition
void LUdecomposition(Matrix a, Matrix l, Matrix u, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Upper Triangular
        for (int k = i; k < n; k++)
        {
            // Summation of L(i, j) * U(j, k)
            int sum = 0;
            for (int j = 0; j < i; j++)
                sum += (l.GetElement(i, j) * u.GetElement(j, k));

            u.SetElement(i, k, a.GetElement(i, k) - sum);
        }

        // Lower Triangular
        for (int k = i; k < n; k++)
        {
            if (i == k)
                l.SetElement(i, i, 1); // Diagonal as 1
            else
            {
                // Summation of L(k, j) * U(j, i)
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (l.GetElement(k, j) * u.GetElement(j, i));

                l.SetElement(k, i, (a.GetElement(k, i) - sum) / u.GetElement(i, i));
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

void LUP(Matrix A, Matrix C, Matrix P, Matrix X) 
{
    // Size of the matrix
    int size = A.GetSize();

    // Filling the main diagonal with 1's
    for (int i = 0; i < size; i++)
    {
        P.SetElement(i, i, 1);
    }

    // Transformation the C matrix, so that C = L + U - E
    for (int i = 0; i < size; i++) {
        float pivotValue = 0;
        int pivot = -1;
        for (int row = i; row < size; row++) {
            if (fabs(C.GetElement(row, i)) > pivotValue) {
                pivotValue = fabs(C.GetElement(row, i));
                pivot = row;
            }
        }
        if (pivotValue != 0) {
            SwapRows(P, pivot, i);
            SwapRows(C, pivot, i);
            for (int j = i + 1; j < size; j++) {
                C.SetElement(j, i, C.GetElement(j, i) / C.GetElement(i, i));
                for (int k = i + 1; k < size; k++)
                    C.SetElement(j, k, C.GetElement(j, k) - C.GetElement(j, i) * C.GetElement(i, k));
            }
        }
    }

    // Finding Matrix X
    for (int k = size - 1; k >= 0; k--) {
        X.SetElement(k, k, 1);
        for (int j = size - 1; j > k; j--)
        {
            X.SetElement(k, k, X.GetElement(k, k) - C.GetElement(k, j) * X.GetElement(j, k));
        }
        X.SetElement(k, k, X.GetElement(k, k) / C.GetElement(k, k));
        for (int i = k - 1; i >= 0; i--)
        {
            for (int j = size - 1; j > i; j--)
            {
                X.SetElement(i, k, X.GetElement(i, k) - C.GetElement(i, j) * X.GetElement(j, k));
                X.SetElement(k, i, X.GetElement(k, i) - C.GetElement(j, i) * X.GetElement(k, j));
            }
            X.SetElement(i, k, X.GetElement(i, k) / C.GetElement(i, i));
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
            exit(0);
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