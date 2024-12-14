#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int x, y;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    sort(v.begin(), v.end(), [&](const auto& a, const auto& b)
        { 
            if (a.second < b.second) return true;
            if (a.second > b.second) return false;

            if (a.first < b.first) return true;
            if (a.first > b.first) return false;

            return true;
        });

    for (const auto& item : v)
    {
        cout << item.first << " " << item.second << '\n';
    }
}