#include "Header.h"
#include "Class.h"

void find_b(SquareMatrix* array, int size1)
{
    int largest = array[0].find_trace();
    int num = 1;
    for (int i = 1; i < size1; i++)
    {
        if (largest > array[i].find_trace())
        {
            largest = array[i].find_trace();
            num = i + 1;
        }
    }
    cout << endl << "Matrix " << num << " has the biggest trace: " << largest << endl;
}