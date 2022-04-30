#pragma once
#include "Header.h"

class SquareMatrix
{
private:
    int** M;
    int size;

public:
    SquareMatrix()
    {
        size = 0;
        M = nullptr;
    }

    SquareMatrix(int _size, int min, int max)
    {
        ;
        size = _size;
        M = new int* [size];
        for (int i = 0; i < size; i++)
        {
            M[i] = new int[size];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                M[i][j] = rand() % (max - min) + min;
            }
        }
    }
    int find_trace()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += M[i][i];
        }
        return sum;
    }
    void Print()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << endl;
    }
};
