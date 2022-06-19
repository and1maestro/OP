#include <iostream>
#include <string>
#include "Func.h"
using namespace std;

int tabs = 0;
int k = 0;

int main()
{
	Node* Root = 0;
	int num_of_el;
	string element;
	string element2;

	cout << "Enter the amount of elements in your tree: ";
	cin >> num_of_el;
	cout << endl;

	for (int i = 0; i < num_of_el + 1; i++)
	{
		getline(cin, element);
		Add(element, Root);
	}

	cout << "Your tree: " << endl;
	Print(Root);
	cout << endl;

	int level = 0;
	cout << "Type in the word you want to find: ";
	getline(cin, element2);
	Search(Root, element2, level);
}