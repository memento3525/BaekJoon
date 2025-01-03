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

    int n, arrived, duration;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> arrived >> duration;
        v.push_back({ arrived, duration });
    }

    sort(v.begin(), v.end());

    priority_queue<pair<int, int>> pq;

    int index = 0;
    int time = 0;
    int curDuration = 0;
    while (index != v.size() || pq.size() || curDuration > 0)
    {
        ++time;
        while (index < v.size() && v[index].first <= time)
        {
            pq.push(v[index]);
            ++index;
        }

        if (curDuration > 0)
            --curDuration;

        if (curDuration == 0)
        {
            if (pq.size())
            {
                curDuration = pq.top().second;
                pq.pop();
            }
        }
    }

    cout << time;
}