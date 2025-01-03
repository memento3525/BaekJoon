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

    int n, k, a, b;
    cin >> n >> k;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    vector<int> bag(k);
    for (int i = 0; i < k; ++i)
        cin >> bag[i];

    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;

    long long ret = 0;
    int j = 0;
    for (int i = 0; i < k; ++i)
    {
        while (j < n && v[j].first <= bag[i])
        {
            pq.push(v[j].second);
            ++j;
        }

        if (pq.size())
        {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret;
}