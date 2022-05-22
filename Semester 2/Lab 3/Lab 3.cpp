#include "Header.h"
#include "Class.h"

int main()
{
    srand(time(NULL));
    int min, max;
    cout << "Enter the min and the max numbers of the range: " << endl;
    cin >> min;
    cin >> max;
    SquareMatrix M1 = SquareMatrix(min,max);
    M1.Print();
    SquareMatrix M2 = SquareMatrix(min, max);
    M2.Print();
    SquareMatrix M3 = M1 * M2;
    M3.Print();
    ++M3;
    M3.Print();
    cout << "Determinant of the third matrix: " << M3.Determinant() << endl;
}