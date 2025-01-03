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

    int n, arriv, duration;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> arriv >> duration;
        v.push_back({ arriv, duration });
    }

    sort(v.begin(), v.end());

    priority_queue<pair<int, int>> pq;

    int i = 0, t = 0, d = 0;
    while (i != v.size() || pq.size() || d > 0)
    {
        ++t;

        if (d > 0)
            --d;

        if (d == 0)
        {
            while (i < v.size() && v[i].first <= t)
            {
                pq.push(v[i]);
                ++i;
            }

            if (pq.size())
            {
                d = pq.top().second;
                pq.pop();
            }
        }
    }

    cout << t;
}