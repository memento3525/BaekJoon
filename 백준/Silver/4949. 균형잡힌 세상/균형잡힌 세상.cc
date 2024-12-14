#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    vector<char> v;
    while (getline(cin, str))
    {
        if (str == ".") break;

        v.clear();
        string result = "yes";
        for (const char& c : str)
        {
            if (c == '(')
            {
                v.emplace_back('(');
            }
            else if (c == '[')
            {
                v.emplace_back('[');
            }
            else if (c == ']')
            {
                if (v.empty() || v.back() != '[')
                {
                    result = "no";
                    break;
                }
                else
                {
                    v.pop_back();
                }
            }
            else if (c == ')')
            {
                if (v.empty() || v.back() != '(')
                {
                    result = "no";
                    break;
                }
                else
                {
                    v.pop_back();
                }
            }
        }

        if (!v.empty())
            result = "no";

        cout << result << '\n';
    }
}