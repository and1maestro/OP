#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string Data;
	Node* LeftBranch;
	Node* RightBranch;
};
 
void Add(string aData, Node*& aBranch);
void Print(Node* aBranch);
void Search(Node* root, string data, int level);