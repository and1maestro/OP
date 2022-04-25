#pragma once
#include "Header.h"

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