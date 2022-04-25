#include "Header.h"
#include "Structures.h"

int main()
{
    string first_file = "first file.txt";
    string second_file = "second file.txt";

    int size;
    cout << "List size: ";
    cin >> size;

    create_first_file(first_file, size);
    cout << endl << "First file:" << endl;
    output_difference(first_file);

    create_second_file(first_file, second_file, size);
    cout << endl << "Second file:" << endl;
    output_file(second_file);
    cout << endl;
}