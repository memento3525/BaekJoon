#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    cin >> str;

    for (string s : { "pi", "ka", "chu" })
    {
        while (!str.empty())
        {
            auto pos = str.find(s);
            if (pos == string::npos)
                break;

            str.replace(pos, s.size(), "_");
        }
    }

    bool can = true;
    for (char c : str)
    {
        if (c != '_')
        {
            can = false;
            break;
        }
    }

    cout << (can ? "YES" : "NO");
}