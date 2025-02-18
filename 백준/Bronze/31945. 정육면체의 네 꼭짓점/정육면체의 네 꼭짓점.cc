#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    string v[8] = { "000","001", "010", "011", "100", "101", "110", "111" };

    vector<int> a(4);
    map<char, int> mp[3];
    while (t--)
    {
        mp[0].clear();
        mp[1].clear();
        mp[2].clear();
        cin >> a[0] >> a[1] >> a[2] >> a[3];

        for (int i : a)
        {
            string str = v[i];
            mp[0][str[0]]++;
            mp[1][str[1]]++;
            mp[2][str[2]]++;
        }

        bool any = false;
        for (const auto& m : mp)
        {
            for (const auto& pair : m)
            {
                if (pair.second == 4)
                {
                    any = true;
                    break;
                }
            }
        }

        cout << (any ? "YES" : "NO") << '\n';
    }
}