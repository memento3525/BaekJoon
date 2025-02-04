#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, t;
int person[301];
int dp[301][301]; // 구간인덱스, 밖에 있는 영선이친구, 이전에 얼마나 투입했는가
vector<pair<int, int>> v; // 구간시간, 구간인원 

int Go(int here, int remain, int prev)
{
    if (here == v.size())
        return 0;

    int& ret = dp[here][remain];
    if (ret) return ret;

    int require = max(0, t - v[here].second);
    int real_cost = (prev >= require) ? 0 : require;

    if (remain - real_cost >= 0)
    {
        ret = max(
            Go(here + 1, remain - real_cost, require) + v[here].first,
            Go(here + 1, remain, 0)
        );
    }
    else
    {
        ret = max(
            ret, 
            Go(here + 1, remain, 0)
        );
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> t;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        for (int j = a; j < b; ++j)
        {
            // t명이 넘는 인원은 기록할 필요가 없다.
            // 구간이 좀 더 안나눠질 수 있다.
            person[j] = min(t, person[j] + 1);
        }
    }

    int personCnt = person[1];
    int duration = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (personCnt != person[i])
        {
            v.push_back({ duration, personCnt });
            duration = 0;
            personCnt = person[i];
        }
        ++duration;
    }
    v.push_back({ duration, personCnt });

    cout << Go(0, k, 0);
}