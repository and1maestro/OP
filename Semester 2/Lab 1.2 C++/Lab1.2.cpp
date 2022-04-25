#include "Header.h"
#include "Structures.h"

struct Date
{
    int year;
    void set_date()
    {
        cin >> year;
    }
    string get_date()
    {
        string line;
        line = to_string(year);
        return line;
    }
};

struct Work
{
    string name;
    Date date_of_finishing{}, date_of_publication{};
    void create_work_struct()
    {
        cin >> name;
        date_of_finishing.set_date();
        date_of_publication.set_date();
    }
    string get_work()
    {
        string line;
        line += "Name: " + name + "; ";
        line += "Date of finishing: " + date_of_finishing.get_date() + "; ";
        line += "Date of publication: " + date_of_publication.get_date();

        return line;
    }
};

bool difference(Work book)
{
    if (book.date_of_publication.year - book.date_of_finishing.year > 5)
        return true;
    else
        return false;
}

void create_first_file(string name, Work* book, int size)
{
    ofstream fileout;
    fileout.open(name, ios::out | ios::binary);

    if (!fileout.is_open())
    {
        cout << "ERROR" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            book[i].create_work_struct();
            fileout.write((char*)&book[i], sizeof(Work));
        }
    }
    fileout.close();
}

void output_first_file(string name, int size)
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

bool recent(Work book)
{
    if (2022 - book.date_of_finishing.year < 5)
        return true;
    else
        return false;
}

void create_second_file(string filein_name, string fileout_name, Work* book, int size)
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

int main()
{
    string first_file_name = "first file.txt";
    string second_file_name = "second file.txt";

    int size;
    cout << "List size: ";
    cin >> size;
    Work* book = new Work[size];

    create_first_file(first_file_name, book, size);
    cout << endl << "First file:" << endl;
    output_first_file(first_file_name, size);

    create_second_file(first_file_name, second_file_name, book, size);
    cout << endl << "Second file:" << endl;
    output_second_file(second_file_name, size);
    cout << endl;
}