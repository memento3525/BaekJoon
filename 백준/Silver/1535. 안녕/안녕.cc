#include <iostream>
#include <vector>
using namespace std;

int n;
int dmg[21];
int joy[21];
int dp[21][101];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> dmg[i];

    for (int i = 1; i <= n; ++i)
        cin >> joy[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int h = 1; h <= 100; ++h)
        {
            if (h > dmg[i]) // 담을 수 있음
            {
                dp[i][h] = max(
                    dp[i - 1][h], // 안담고 이전꺼 쓰는 경우
                    dp[i - 1][h - dmg[i]] + joy[i] // 담는 경우
                );
            }
            else // 못담음
            {
                dp[i][h] = dp[i - 1][h];
            }
        }
    }

    cout << dp[n][100];
}