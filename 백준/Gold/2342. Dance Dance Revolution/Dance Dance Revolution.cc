#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int energy[5][5] =
{
    { 0, 2, 2, 2, 2 },
    { 0, 1, 3, 4, 3 },
    { 0, 3, 1, 3, 4 },
    { 0, 4, 3, 1, 3 },
    { 0, 3, 4, 3, 1 }
};

int n;
int p[100001];
int dp[100001][5][5];

int Go(int here, int a, int b)
{
    if (here > n) return 0;

    int& ret = dp[here][a][b];
    if (ret != INF) return ret;

    int target = p[here];
    if (target != b)
        ret = min(ret, Go(here + 1, target, b) + energy[a][target]);

    if (target != a)
        ret = min(ret, Go(here + 1, a, target) + energy[b][target]);

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0][0], &dp[0][0][0] + 5 * 5 * 100001, INF);

    int i = 0;
    while (cin >> p[i])
    {
        if (p[i] == 0)
        {
            n = i;
            break;
        }

        ++i;
    }

    if (n == 0)
        cout << 0;
    else
        cout << Go(0, 0, 0);
}