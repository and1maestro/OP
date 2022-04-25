#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Date;
struct Work;
bool difference(Work book);
void create_first_file(string name, int size);
void output_difference(string name);
void output_file(string name);
void create_second_file(string filein_name, string fileout_name, int size);
bool recent(Work);