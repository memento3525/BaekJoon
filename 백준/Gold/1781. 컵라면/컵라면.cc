#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, day, cup;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> day >> cup;
        v.push_back({ day, cup });
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i)
    {
        pq.push(v[i].second);

        if (pq.size() > v[i].first)
            pq.pop();
    }

    int ret = 0;
    while(pq.size())
    {
        ret += pq.top();
        pq.pop();
    }

    cout << ret;
}