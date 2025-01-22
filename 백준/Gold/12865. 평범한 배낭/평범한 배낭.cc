#include <iostream>
#include <vector>
using namespace std;

int n, k;
int dp[101][1000001];
int w[101];
int v[101]; // 페어로 할당해도됨

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int wi = 1; wi <= k; ++wi)
        {
            if (wi - w[i] >= 0) // 담을 수 있는 경우
            {
                dp[i][wi] = max(
                    dp[i - 1][wi], // 이전 꺼를 담는 경우
                    dp[i - 1][wi - w[i]] + v[i]); // 이전 꺼를 안담고 이걸 담는 경우
            }
            else // 못담는 경우
            {
                dp[i][wi] = dp[i - 1][wi];
            }
        }
    }

    cout << dp[n][k];
}