#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void input_file(string name)
{
    ofstream fileout;
    fileout.open(name);

    string line;
    cout << "Enter text (to stop typing, press Ctrl + Z and confirm with Enter)::" << endl;
    getline(cin, line);
    while (true)
    {
        fileout << line << "\n";
        getline(cin, line);
        if (cin.eof())
        {
            break;
        }
    }
    fileout.close();
}

void output_file(string name)
{
    ifstream filein;
    filein.open(name);

    if (!filein.is_open())
    {
        cout << "ERROR";
    }
    else
    {
        string line;
        while (!filein.eof())
        {
            getline(filein, line);
            cout << line << endl;
        }
    }

    filein.close();
}

string delete_spaces(string text)
{
    bool space_sleep = false;
    string res;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ' && space_sleep == true)
        {
            continue;
        }
        if (text[i] == ' ' && space_sleep == false)
        {
            res.push_back(text[i]);
            space_sleep = true;
        }
        else
        {
            res.push_back(text[i]);
            space_sleep = false;
        }
    }
    if (res[res.length()] == ' ')
    {
        res.erase(res.length() - 1, 1);
    }
    if (res[0] == ' ')
    {
        res.erase(0, 1);
    }
    string count = " " + to_string(text.length() - res.length());
    res = res + count;
    return res;
}

void create_new_file(string filein_name, string fileout_name)
{
    ifstream filein;
    ofstream fileout;
    filein.open(filein_name);
    fileout.open(fileout_name);

    if (!filein.is_open() || !fileout.is_open())
    {
        cout << "ERROR";
    }
    else
    {
        string line;
        while (!filein.eof())
        {
            getline(filein, line);
            if (!line.empty())
            {
                string res = delete_spaces(line);
                fileout << res << endl;
            }
        }
    }
    filein.close();
    fileout.close();
}

int main()
{
    string first_file_name = "first.txt";
    string second_file_name = "second.txt";
    input_file(first_file_name);

    cout << "\nContents of first file:" << endl;
    output_file(first_file_name);

    create_new_file(first_file_name, second_file_name);

    cout << "Contents of second file:" << endl;
    output_file(second_file_name);
}