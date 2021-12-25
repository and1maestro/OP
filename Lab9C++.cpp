#include <iostream>
#include <string>
using namespace std;

int str(int a)
{
    char* intStr = itoa(a);
    string str = string(intStr);
}

int freq(string a, string b)
{
    int n = 0;
    int len = b.length();
    for (size_t i = 0; i < len; i++)
    {
        if (b[i] == a)
        {
            n++;
        }
    }
}

int minmax(string text)
{
    string CharNum = "";
    int minn = text.length();
    int maxx = 0;
    string min = "";
    string max = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (find(begin(text), end(text), i) != end(text))
            if (freq(i,text) > maxx)
            {
                maxx = freq(i, text);
                max = str(i);
            }
            else if (freq(i, text) == maxx)
            {
                max = max + " " + str(i);
            }
            if (freq(i, text) < minn)
            {
                minn = freq(i, text);
                min = str(i);
            }
            else if (freq(i, text) == minn)
            {
                min = min + " " + str(i);
                CharNum = CharNum + i;
            }
    }
    string result = "Max: " + max + " " + str(maxx) + " time(s)" + "\n" + "Min: " + min + " " + str(minn) + " time(s)";
    return result
}

int main()
{
    string your_text;
    cout << "Enter your text: ";
    cin >> your_text;
    cout << your_text;
    string res = minmax(your_text);
    cout << res;
}