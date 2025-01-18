#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 16;

int n;
int dp[MAX_N][1 << MAX_N];
int cost[MAX_N][MAX_N];
int INF = 999999999;

int Go(int here, int visited)
{
    if (visited == (1 << n) - 1)
    {
        return cost[here][0] ? cost[here][0] : INF;
    }

    int &ret = dp[here][visited];
    if (ret != -1) return ret;

    ret = INF;
    for (int i = 0; i < n; ++i)
    {
        if (visited & (1 << i)) continue;
        if (cost[here][i] == 0) continue;

        ret = min(ret, Go(i, visited | (1 << i)) + cost[here][i]);
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            cin >> cost[y][x];
    }

    memset(dp, -1, sizeof(dp));

    cout << Go(0, 1);
}