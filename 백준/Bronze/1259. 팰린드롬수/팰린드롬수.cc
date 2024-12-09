#include <iostream>
using namespace std;
bool IsPalindrome(string str);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (cin >> str)
    {
        if (str == "0")
            break;

        cout << (IsPalindrome(str) ? "yes" : "no") << '\n';
    }
}

bool IsPalindrome(string str)
{
    for (int i = 0; i < str.size() / 2; ++i)
    {
        if (str[i] != str[str.size() - i - 1])
            return false;
    }

    return true;
}