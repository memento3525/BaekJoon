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

    vector<pair<int, int>> v(n);
    int x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        v[i] = std::make_pair(x, y);
    }

    sort(v.begin(), v.end());

    for (const auto& item : v)
    {
        cout << item.first << " " << item.second << '\n';
    }
}