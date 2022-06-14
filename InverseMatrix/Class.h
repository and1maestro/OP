#pragma once
#include "Func.h"

class Matrix
{
private:
    float** M;
    int size;
public:
    Matrix()
    {
        M = new float* [1];
        for (int i = 0; i < 1; i++)
        {
            M[i] = new float[1]{};
        }
    }

    Matrix(int size_)
    {
        this->size = size_;
        M = new float* [size_];
        for (int i = 0; i < size_; i++)
        {
            M[i] = new float[size_] {};
        }
        for (int i = 0; i < size_; i++)
        {
            for (int j = 0; j < size_; j++)
            {
                M[i][j] = rand() % 10;
            }
        }
    }

    Matrix(int size_, int num)
    {
        this->size = size_;
        M = new float* [size_];
        for (int i = 0; i < size_; i++)
        {
            M[i] = new float[size_] {};
        }
        for (int i = 0; i < size_; i++)
        {
            for (int j = 0; j < size_; j++)
            {
                M[i][j] = num;
            }
        }
    }

    float GetElement(int x, int y)
    {
        return M[x][y];
    }

    void SetElement(int x, int y, float num)
    {
        M[x][y] = num;
    }

    int GetSize()
    {
        return size;
    }

    void SetSize(int size_)
    {
        size = size_;
        M = new float* [size_];
        for (int i = 0; i < size_; i++)
        {
            M[i] = new float[size] {};
        }
    }

    // Filling the matrix with random numbers
    void Random()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                M[i][j] = rand() % 10;
            }
        }
    }

    float* GetRow(int row)
    {
        return M[row];
    }

    void SetRow(int row_, float* row)
    {
        M[row_] = row;
    }

    // Filling the matrix with zeros
    void Zero()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                M[i][j] = 0;
            }
        }
    }

    Matrix operator * (Matrix Matrix2)
    {
        Matrix results = Matrix(size);
        results.Zero();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int u = 0; u < size; u++)
                {
                    results.SetElement(i, j, (results.GetElement(i, j) + M[i][u] * Matrix2.GetElement(u, j)));
                }
            }
        }
        return results;
    }

};