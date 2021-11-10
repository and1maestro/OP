#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    int sd, num, n, max = 0;

    cout << "Введiть n = ";
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int accum = 0;
        for (int a = 1; a < i; ++a)
        {
            if (i % a == 0)
                accum += a;
        }
        sd = accum;
        if (max < sd)
        {
            max = sd;
            num = i;
        }
    }
    cout << "Максимальна сума дiльникiв " << max << " у числа " << num << endl;

    system("pause");
}