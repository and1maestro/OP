#pragma once
#include "Header.h"

class SquareMatrix
{
private:
    int** M;

public:
    SquareMatrix()
    {
        M = new int* [3];
        for (int i = 0; i < 3; i++)
        {
            M[i] = new int[3];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                M[i][j] = 0;
            }
        }
    }

    SquareMatrix(int min, int max)
    {
        M = new int* [3];
        for (int i = 0; i < 3; i++)
        {
            M[i] = new int[3];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                M[i][j] = rand() % (max - min) + min;
            }
        }
    }

    int GetElement(int x, int y)
    {
        return M[x][y];
    }

    void SetElement(int x, int y, int num)
    {
        M[x][y] = num;
    }

    void Print()
    {
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << endl;
    }

    int Determinant()
    {
        int x,y,z,det;
        x = ((M[1][1] * M[2][2]) - (M[2][1] * M[1][2]));
        y = ((M[1][0] * M[2][2]) - (M[2][0] * M[1][2]));
        z = ((M[1][0] * M[2][1]) - (M[2][0] * M[1][1]));

        det = ((M[0][0] * x) - (M[0][1] * y) + (M[0][2] * z));
        return det;
    }

    SquareMatrix & operator++()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                M[i][j]++;
            }
        }
        return *this;
    }

    SquareMatrix operator * (SquareMatrix Matrix2)
    {
        SquareMatrix results;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int u = 0; u < 3; u++)
                {
                    results.SetElement(i, j, (results.GetElement(i,j) + M[i][u] * Matrix2.GetElement(u, j)));
                }
            }
        }
        return results;
    }
};