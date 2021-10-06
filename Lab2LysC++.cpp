#include <iostream>;
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float x, y;
	cout << "Введіть значення x=";
	cin >> x;
	cout << "Введіть значення y=";
	cin >> y;

	if (x >= -3 & x <= 3 & y >= -3 & y <= 3)
	{
		if (pow(x, 2) + pow(y, 2) >= 9)
		{
			if (x < 0 & y>0)
				cout << "Не належить";
			else
				cout << "Належить";
		}
		else
			cout << "Не належить";
	}
	else 
		cout << "Не належить";
	cin.get();
}