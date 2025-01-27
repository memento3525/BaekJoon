#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<char, char> sortMap
    {
        { 'a', 'a' },
        { 'b', 'b' },
        { 'k', 'c' },
        { 'd', 'd' },
        { 'e', 'e' },
        { 'g', 'f' },
        { 'h', 'g' },
        { 'i', 'h' },
        { 'l', 'i' },
        { 'm', 'j' },
        { 'n', 'k' },
        { '?', 'l' },
        { 'o', 'm' },
        { 'p', 'n' },
        { 'r', 'o' },
        { 's', 'p' },
        { 't', 'q' },
        { 'u', 'r' },
        { 'w', 's' },
        { 'y', 't' }
    };

    int n;
    cin >> n;

    vector<string> str(n);
    for (int i = 0; i < n; ++i)
        cin >> str[i];

    stringstream ss;
    vector<pair<string, string>> sortList(n);

    for(int i = 0; i < n; ++i)
    {
        const string s = str[i];

        ss.clear();
        ss.str("");
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (c == 'n' && (i + 1 < s.size()) && s[i + 1] == 'g')
                ss << sortMap['?'];
            else
                ss << sortMap[c];
        }

        sortList[i] = { ss.str(), s };
    }

    sort(sortList.begin(), sortList.end());

    for (const auto& s : sortList)
        cout << s.second << '\n';
}