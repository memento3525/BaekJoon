#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string name, s[3];
vector<pair<int, string>> p;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> name >> s[2] >> s[1] >> s[0];

        string day = "";
        for (int i = 0; i < 3; i++)
        {
            if (s[i].size() == 1)
                day += '0' + s[i];
            else
                day += s[i];
        }

        int num = stoi(day);
        p.push_back({ num, name });
    }

    sort(p.begin(), p.end());

    cout << p.back().second << '\n' << p.front().second << '\n';
}