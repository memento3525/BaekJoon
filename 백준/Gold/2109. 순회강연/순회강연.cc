#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, pay;
    cin >> n;

    // greater를 최대힙. 제일 낮은 값이 위로 올라감
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> pay >> d;
        v[i] = { d, pay };
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        pq.push(v[i].second);

        // 매번 넣을 때마다 최악(젤 싼거)을 삭제
        if (pq.size() > v[i].first)
            pq.pop();
    }

    int ret = 0;
    while (pq.size())
    {
        ret += pq.top();
        pq.pop();
    }

    cout << ret;
}