#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int const MAX = 1e6 + 1;
int dp[MAX];
int minCnt = INT32_MAX;

void Go(int n, int cnt)
{
    if (n == 0) return;
    cout << n << ' ';

    if (n % 3 == 0 && (cnt - 1 == dp[n / 3]))
        Go(n / 3, cnt - 1);
    else if (n % 2 == 0 && (cnt - 1 == dp[n / 2]))
        Go(n / 2, cnt - 1);
    else if ((cnt - 1) == dp[n - 1])
        Go(n - 1, cnt - 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0], &dp[0] + MAX, 1e9);

    int n;
    cin >> n;

    dp[1] = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[n] << '\n';
    Go(n, dp[n]);
}