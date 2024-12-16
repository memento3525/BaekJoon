#include <iostream>
using namespace std;

string p_pre;
string p_after;

bool IsMatching(const string& str)
{
    if (p_pre.size() + p_after.size() > str.size()) return false;

    for (int i = 0; i < p_pre.size(); ++i)
    {
        if (p_pre[i] != str[i])
            return false;
    }

    for (int i = 0; i < p_after.size(); ++i)
    {
        int curIndex = str.size() - p_after.size() + i;
        if (p_after[i] != str[curIndex])
            return false;
    }

    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    const int pos = (int)pattern.find('*');

    p_pre = string(pattern.begin(), pattern.begin() + pos);
    p_after = string(pattern.begin() + pos + 1, pattern.end());

    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        cout << (IsMatching(str) ? "DA" : "NE") << '\n';
    }
}