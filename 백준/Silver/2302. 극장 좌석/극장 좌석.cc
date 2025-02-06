#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, dp[41], vip[41];

int Go(int i)
{
    if (i >= n - 1) return 1;
    if (vip[i]) return Go(i + 1);

    int& ret = dp[i];
    if (ret != -1) return ret;

    ret = 0;
    if (vip[i + 1])
        ret += Go(i + 1);
    else
        ret += Go(i + 1) + Go(i + 2);

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(dp, dp + 41, -1);

    cin >> n >> m;

    int vipTemp;
    for (int i = 0; i < m; ++i)
    {
        cin >> vipTemp;
        vip[vipTemp - 1] = 1;
    }

    cout << Go(0);
}