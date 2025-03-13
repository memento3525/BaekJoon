#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int n, cnt[26];
string s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();

    int caseNum = 0;
    while (n--)
    {
        fill(cnt, cnt + 26, 0);
        ++caseNum;

        getline(cin, s);

        for (char c : s)
        {
            if (isalpha(c))
                islower(c) ? cnt[c - 'a']++ : cnt[c - 'A']++;
        }

        int ret = 999;
        for (int i = 0; i < 26; i++)
            ret = min(ret, cnt[i]);

        cout << "Case " << caseNum << ": ";

        if (ret == 0)
            cout << "Not a pangram\n";
        else if (ret == 1)
            cout << "Pangram!\n";
        else if (ret == 2)
            cout << "Double pangram!!\n";
        else
            cout << "Triple pangram!!!\n";
    }
}