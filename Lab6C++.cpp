#include <iostream>
using namespace std;

int sum(int n)
{
    int sd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            sd += i;
    }
    return sd;
}

void friendlyNumbers(int n)
{
    int x = 2;
    for (x; x < n; x++)
    {
        int y;
        y = sum(x) - x;
        if ((sum(x) - x) == y && (sum(y) - y) == x && x != y && (y - x) > 0)
            cout << x << " and " << y << " are friendly numbers";
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    friendlyNumbers(n);

    system("pause");
}