#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int r, c, rrank[10];
vector<pair<int, int>> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    while (r--)
    {
        cin >> s;
        for (int i = s.size() - 2; i >= 1; --i)
        {
            if (s[i] != '.')
            {
                v.push_back(make_pair(i, s[i] - '0'));
                break;
            }
        }
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    int curRank = 1;
    int curMax = v[0].first;
    for (int i = 0; i < v.size(); ++i)
    {
        if (curMax != v[i].first)
        {
            ++curRank;
            curMax = v[i].first;
        }

        rrank[v[i].second] = curRank;
    }

    for (int i = 1; i < 10; ++i)
        cout << rrank[i] << '\n';
}