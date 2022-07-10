#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

class Account;
class Array;
class List;
void input_file(string name, int size);
void output_file(List& L, string name, int size);
Account smallest(List L);
List Bigger(List L, int num);