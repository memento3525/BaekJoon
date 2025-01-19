#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v;
int dp[1000][3];

int Go(int here, int curColor)
{
    if (here == n)
        return 0;

    int& ret = dp[here][curColor];
    if (ret != INT32_MAX)
        return ret;

    for (int i = 0; i < 3; ++i)
    {
        if (i == curColor) continue;
        ret = min(ret, Go(here + 1, i) + v[here][curColor]);
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    v.assign(n, vector<int>(3));
    
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < 3; ++x)
            cin >> v[y][x];
    }

    fill(&dp[0][0], &dp[0][0] + 1000 * 3, INT32_MAX);

    int minRet = INT32_MAX;
    for (int i = 0; i < 3; ++i)
        minRet = min(minRet, Go(0, i));

    cout << minRet;
}
