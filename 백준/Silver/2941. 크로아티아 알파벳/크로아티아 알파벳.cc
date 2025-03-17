#include <iostream>
#include <string>
using namespace std;

string s;
int ret;

string m[8] =
{
    { "c=" },
    { "c-" },
    { "dz=" },
    { "d-" },
    { "lj" },
    { "nj" },
    { "s=" },
    { "z=" }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    for (const string& i : m)
    {
        size_t pos = 0;
        while ((pos = s.find(i, pos)) != string::npos)
        {
            s.replace(pos, i.length(), " ");
            ++ret;
        }
    }

    for (const char& c : s)
    {
        if (c != ' ')
            ++ret;
    }

    cout << ret;
}