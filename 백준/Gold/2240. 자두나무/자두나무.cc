#include <iostream>
#include <vector>
using namespace std;

int t, w;
vector<int> v;
int dp[1000][2][30];

int Go(int tt, int pos, int m)
{
    if (tt == t) return 0;
    if (m < 0) return -1001;

    int& ret = dp[tt][pos][m];
    if (ret != -1) return ret;

    int cur = (pos == v[tt] - 1);
    ret = max(Go(tt + 1, pos, m), Go(tt + 1, pos ^ 1, m - 1)) + cur;
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0][0], &dp[0][0][0] + 1000 * 2 * 30, -1);

    cin >> t >> w;
    v.resize(t);

    for (int i = 0; i < t; ++i)
        cin >> v[i];

    cout << (max(Go(0, 0, w), Go(0, 1, w - 1)));
}