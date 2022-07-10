#pragma once
#include "Header.h"

class Account
{
public:
	string n;
	string l_n;
	string m_n;
	int hrn;
	int kop;
	Account()
	{
		n = "";
		l_n = "";
		m_n = "";
		hrn = 0;
		kop = 0;
	}
	void create()
	{
		cout << "Name: ";
		cin >> n;
		cout << "Last Name: ";
		cin >> l_n;
		cout << "Middle Name: ";
		cin >> m_n;
		cout << "Hrn: ";
		cin >> hrn;
		cout << "Kop: ";
		cin >> kop;
	}
	void print()
	{
		cout << "Name: " << l_n << " " << n << " " << m_n << ", Money: " << hrn << "." << kop << " hrn" << endl;
	}
};

class Array
{
public:
	Account* arr;
	int size;
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	Array(int size)
	{
		arr = new Account[size]{};
		this->size = size;
	}
	void add(Account A, int ind)
	{
		arr[ind] = A;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i].print();
		}
	}
	Account operator [](int index)
	{
		assert(index >= 0 && index < size);
		return arr[index];
	}
};

class List : Account
{
public:
	int size;
	vector<Account> v;
	List()
	{
		int size = 0;
	}
	void push(Account A)
	{
		v.push_back(A);
		size++;
	}
	void print()
	{
		for (auto i : v)
		{
			i.print();
		}
	}
	Account operator [](int index)
	{
		assert(index >= 0 && index < size);
		return v[index];
	}
	void operator += (Account A)
	{
		v.push_back(A);
		size++;
	}
};

