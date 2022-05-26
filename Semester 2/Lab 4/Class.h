#pragma once
#include "Header.h"

class TMatrix
{
public:
    double** M;
    int rows, cols;

    TMatrix()
    {
        rows = 1;
        cols = 1;
        M = new double* [rows];
        for (int i = 0; i < rows; i++)
        {
            M[i] = new double[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                M[i][j] = 0;
            }
        }
    }

    TMatrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
        M = new double* [rows];
        for (int i = 0; i < rows; i++)
        {
            M[i] = new double[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                M[i][j] = (rand() % 100000) / static_cast<double>(100) - 500;
            }
        }
    }

    void Print()
    {
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << endl;
    }

    void Incrementation(int num)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                M[i][j] += num;
            }
        }
    }

    double Average()
    {
        double sum = 0;
        double avg = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sum += M[i][j];
            }
        }
        avg = sum / (rows * cols);
        return avg;
    }

};

class IMatrix : public TMatrix
{
public:

    IMatrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
        M = new double* [rows];
        for (int i = 0; i < rows; i++)
        {
            M[i] = new double[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                M[i][j] = rand() % 1000 - 500;
            }
        }
    }
};

class DMatrix : public TMatrix
{
public:

    DMatrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
        M = new double* [rows];
        for (int i = 0; i < rows; i++)
        {
            M[i] = new double[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                M[i][j] = (rand() % 100000) / static_cast<double>(100) - 500;
            }
        }
    }
};