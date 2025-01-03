#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        v.push_back({ b, a });
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    int time = v[0].first;
    for (int i = 1; i < n; ++i)
    {
        if (v[i].second < time)
            continue;

        time = v[i].first;
        ++cnt;
    }

    cout << cnt;
}