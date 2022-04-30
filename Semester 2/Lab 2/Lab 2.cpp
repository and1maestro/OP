#include "Header.h"
#include "Class.h"

int main()
{
    srand(time(NULL));
    int size, arr_size, min, max;
    cout << "Enter the size of the matrices: ";
    cin >> size;
    cout << "Enter the number of the matrices: ";
    cin >> arr_size;
    cout << "Enter the min and the max numbers of the range: " << endl;
    cin >> min;
    cin >> max;
    SquareMatrix* arr = new SquareMatrix[arr_size]{};
    for (int k = 0; k < arr_size; k++)
    {
        arr[k] = SquareMatrix(size, min, max);
    }
    for (int q = 0; q < arr_size; q++)
    {
        arr[q].Print();
    }
    find_b(arr, arr_size);
}