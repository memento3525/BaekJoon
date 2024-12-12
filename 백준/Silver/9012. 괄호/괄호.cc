#include <iostream>
using namespace std;

void Check(string str)
{
    int count = 0;
    for (const char& c : str)
    {
        if (c == '(')
        {
            ++count;
        }
        else if (c == ')')
        {
            if (count == 0)
            {
                cout << "NO" << '\n';
                return;
            }

            --count;
        }
    }

    cout << ((count == 0) ? "YES" : "NO") << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        Check(str);
    }
}