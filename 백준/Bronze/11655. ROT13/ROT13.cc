#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string result;

    string str;
    while (getline(cin, str))
    {
        for (const char& c : str)
        {
            if (isdigit(c) || c == ' ')
            {
                result += c;
            }
            else if (islower(c))
            {
                result += (char)((c - 'a' + 13) % 26 + 'a');
            }
            else
            {
                result += (char)((c - 'A' + 13) % 26 + 'A');
            }
        }
    }

    cout << result;
}