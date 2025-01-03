#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, d;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> d;
        v.push_back({ a, d });
    }

    sort(v.begin(), v.end());

    int time = 0;
    for (const auto& cow : v)
    {
        if (cow.first > time)
            time = cow.first;

        time += cow.second;
    }

    cout << time;
}