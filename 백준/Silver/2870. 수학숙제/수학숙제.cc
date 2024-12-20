#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string TrimStr(const string& str)
{
    if (str.size() == 1)
        return str;

    string result = "";
    bool allIsZero = true;
    for (const char& c : str)
    {
        if (c == '0')
        {
            if (allIsZero)
                continue;
        }
        else
        {
            allIsZero = false;
        }
        result += c;
    }

    if (allIsZero)
        return "0";

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> v;
    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;

        string numStr = "";
        for(const char& c : str)
        {
            if (isdigit(c))
            {
                numStr += c;
            }
            else
            {
                if (!numStr.empty())
                {
                    v.emplace_back(TrimStr(numStr));
                    numStr = "";
                }
            }
        }

        if (!numStr.empty())
            v.emplace_back(TrimStr(numStr));
    }

    sort(v.begin(), v.end(), [&](const string& a, const string& b)
        {
            if (a.size() == b.size())
                return a < b;
            else
                return a.size() < b.size();
        });

    for (const string& ns : v)
    {
        cout << ns << '\n';
    }
}