#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<char> m = { 'a', 'e', 'i', 'o', 'u' };

bool IsAcceptable(const string& str)
{
    bool isAcceptable = true;

    bool hasAnyVowel = false;
    char pre = '\n';
    bool prepreIsVowel = false;
    bool preVowel = false;

    for (int i = 0; i < str.size(); ++i)
    {
        const char& c = str[i];
        bool isVowel = m.find(c) != m.end();

        if (i >= 2)
        {
            if ((prepreIsVowel == preVowel) && (preVowel == isVowel))
                return false;
        }

        if (isVowel)
            hasAnyVowel = true;

        if (pre == c)
        {
            if (c != 'e' && c != 'o')
                return false;
        }

        prepreIsVowel = preVowel;
        preVowel = isVowel;
        pre = c;
    }

    if (!hasAnyVowel)
        return false;

    return isAcceptable;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    while (cin >> str)
    {
        if (str == "end") break;

        cout << "<" << str << "> is " << (IsAcceptable(str) ? "acceptable." : "not acceptable.") << '\n';
    }
}