#include "Header.h"
#include "Class.h"

int main()
{
    int r, c, arr_size;
    cout << "Enter the amount of rows: ";
    cin >> r;
    cout << "Enter the amount of columns: ";
    cin >> c;
    cout << "Enter the number of the matrices of each type: ";
    cin >> arr_size;
    srand(time(NULL));
    TMatrix* arr = new TMatrix[arr_size * 2]{};
    for (int k = 0; k < arr_size; k++)
    {
        arr[k] = DMatrix(r, c);
        arr[k].Incrementation(-5);
    }
    for (int k = arr_size; k < arr_size * 2; k++)
    {
        arr[k] = IMatrix(r, c);
        arr[k].Incrementation(9);
    }
    for (int q = 0; q < arr_size * 2; q++)
    {
        arr[q].Print();
    }
    double max = arr[0].Average();
    int ind = 0;
    for (int q = 1; q < arr_size * 2; q++)
    {
        if (arr[q].Average() > max)
        {
            max = arr[q].Average();
            ind = q;
        }
    }
    cout << "Matrix " << ind + 1 << " has the biggest arithmetic average of the elements: " << max << endl;
}