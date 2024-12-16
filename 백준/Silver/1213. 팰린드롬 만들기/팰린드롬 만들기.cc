#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int nums[26]{ };

    for (const char& c : str)
    {
        ++nums[c - 'A'];
    }

    int oddCount = 0;
    char oddChar = '\n';
    for (int i = 0; i < 26; ++i)
    {
        if (nums[i] & 1)
        {
            ++oddCount;
            oddChar = char(i + 'A');

            if (oddCount >= 2)
            {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }

    string leftStr;
    for (int i = 0; i < 26; ++i)
    {
        if (nums[i] == 0) continue;

        for (int k = 0; k < nums[i] / 2; ++k)
        {
            leftStr += (char)(i + 'A');
        }
    }
    
    cout << leftStr;

    if (oddChar != '\n')
        cout << oddChar;

    reverse(leftStr.begin(), leftStr.end());

    cout << leftStr;
}