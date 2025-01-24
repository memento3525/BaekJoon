#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
int n, k;
int dp[10001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(dp, dp + 10001, INF);
    dp[0] = 0;

    cin >> n >> k;

    int coin;
    for (int i = 0; i < n; ++i)
    {
        cin >> coin;
        for (int j = coin; j <= k; ++j)
        {
            dp[j] = min(
                dp[j], // 이전꺼 그냥 쓴 경우
                dp[j - coin] + 1 // 이전꺼 대신 이거 쓴 경우
            );
        }
    }

    if (dp[k] == INF)
        cout << -1;
    else
        cout << dp[k];
}