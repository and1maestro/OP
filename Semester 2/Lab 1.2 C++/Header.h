#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Date;
struct Work;
void create_first_file(string, Work*, int);
void output_first_file(string, int);
void create_second_file(string, string, Work*, int);
void output_second_file(string, int);
bool difference(Work);
bool recent(Work);