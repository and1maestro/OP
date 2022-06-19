#include "Func.h"

extern int tabs;
extern int k;

void Add(string aData, Node*& aBranch)
{
	if (!aBranch)
	{
		aBranch = new Node;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else
		if (aBranch->Data > aData)
		{
			Add(aData, aBranch->LeftBranch);
		}
		else
		{
			Add(aData, aBranch->RightBranch);
		};
}

void Print(Node* aBranch)
{
	if (!aBranch) return;
	tabs += 5;
	Print(aBranch->LeftBranch);

	for (int i = 0; i < tabs; i++) cout << " ";
	cout << aBranch->Data << endl;
	Print(aBranch->RightBranch);

	tabs -= 5;
	return;
}

void Search(Node* root, string data, int level)
{
	if (root == NULL) {
		cout << endl << "There is no such word in this tree." << endl;
	}
	else if (root->Data == data) {
		cout << endl << "The word you are looking for is on level " << level << endl;
	}
	else if (data < root->Data) {
		Search(root->LeftBranch, data, level + 1);
	}
	else {
		Search(root->RightBranch, data, level + 1);
	}
}