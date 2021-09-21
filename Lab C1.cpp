#include <iostream>
using namespace std;

#include <math.h>

int main() {
    setlocale(LC_ALL, "Ukrainian");
    double a, b;
    cout << "Введiть кут: ";
    cin >> a;
    b = a * 3.1415926535 / 180;
    cout << b;
    return 0;
}