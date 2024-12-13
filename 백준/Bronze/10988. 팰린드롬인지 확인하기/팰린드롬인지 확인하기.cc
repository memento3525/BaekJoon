#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    for (int i = 0; i < str.size() / 2; ++i)
    {
        if (str[i] != str[str.size() - 1 - i])
        {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}