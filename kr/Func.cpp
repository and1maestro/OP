#include "Header.h"
#include "Classes.h"

void input_file(string name, int size)
{
	ofstream f;
	f.open(name);
	if (!f.is_open())
	{
		cout << "error!";
	}
	else
	{
		string line;
		getline(cin, line);
		for (int i = 0; i < size; i++)
		{
			Account A;
			getline(cin, line);
			f << line << "\n";
			getline(cin, line);
			f << line << "\n";
			getline(cin, line);
			f << line << "\n";
			getline(cin, line);
			f << line << "\n";
			getline(cin, line);
			f << line << "\n";
		}
		f.close();
	}
}

void output_file(List& L, string name, int size)
{
	ifstream f;
	f.open(name);
	if (!f.is_open())
	{
		cout << "error!";
	}
	else
	{
		string line;
		for (int i = 0; i < size; i++)
		{
				Account A;
				getline(f, line);
				A.n = line;
				getline(f, line);
				A.l_n = line;
				getline(f, line);
				A.m_n = line;
				getline(f, line);
				A.hrn = stoi(line);
				getline(f, line);
				A.kop = stoi(line);
				L.push(A);
		}

		f.close();
	}
}

Account smallest(List L)
{
	double min = L[0].hrn + 1;
	Account M = L[0];
	double c = 0;
	for (int i = 0; i < L.size; i++)
	{
		c = L[i].hrn + L[i].kop / 100;
		if (c < min)
		{
			min = c;
			M = L[i];
		}
	}
	return M;
}

List Bigger(List L, int num)
{
	List L1;
	double a = 0;
	for (int i = 0; i < L.size; i++)
	{
		a = L[i].hrn + L[i].kop / 100;
		if (a > num)
		{
			L1 += L[i];
		}
	}
	return L1;
}