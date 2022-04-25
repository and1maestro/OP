#include "Header.h"
#include "Structures.h"

bool difference(Work book)
{
    if (book.date_of_publication.year - book.date_of_finishing.year > 5)
        return true;
    else
        return false;
}

void create_first_file(string name, int size)
{
    ofstream fileout;
    fileout.open(name, ios::out | ios::binary);

    if (!fileout.is_open())
    {
        cout << "ERROR" << endl;
    }
    else
    {
        Work* book = new Work[size];
        for (int i = 0; i < size; i++)
        {
            book[i].create_work_struct();
            fileout.write((char*)&book[i], sizeof(Work));
        }

    }
    fileout.close();
}

void output_difference(string name)
{
    ifstream filein;
    filein.open(name, ios::out | ios::binary);

    Work book;
    if (!filein.is_open())
    {
        cout << "ERROR";
    }
    else
    {
        while (filein.read((char*)&book, sizeof(Work)))
        {
            if (difference(book))
            {
                cout << book.get_work() << endl;
            }
        }
    }
    filein.close();
}

void output_file(string name)
{
    ifstream filein;
    filein.open(name, ios::binary);

    Work book;
    if (!filein.is_open())
    {
        cout << "ERROR";
    }
    else
    {
        while (filein.read((char*)&book, sizeof(Work)))
        {
            cout << book.get_work() << endl;
        }
    }
    filein.close();
}

bool recent(Work book)
{
    if (2022 - book.date_of_finishing.year < 5)
        return true;
    else
        return false;
}

void create_second_file(string filein_name, string fileout_name, int size)
{
    ifstream filein;
    ofstream fileout;
    filein.open(filein_name, ios::out | ios::binary);
    fileout.open(fileout_name, ios::out | ios::binary);

    if (!filein.is_open() || !fileout.is_open())
    {
        cout << "ERROR";
    }
    else
    {
        Work* book = new Work[size];
        for (int i = 0; i < size; i++)
        {
            filein.read((char*)&book[i], sizeof(Work));
            if (recent(book[i]))
            {
                fileout.write((char*)&book[i], sizeof(Work));
            }
        }
    }
    filein.close();
    fileout.close();
}
void output_second_file(string name, int size)
{
    ifstream filein;
    filein.open(name, ios::out | ios::binary);
    Work book;

    if (!filein.is_open())
    {
        cout << "ERROR";
    }
    else
    {
        while (filein.read((char*)&book, sizeof(Work)))
        {
            cout << book.get_work() << endl;
        }
    }
    filein.close();
}