#include <iostream>
#include <vector>
using namespace std;

int n, m;
int day[201];
int page[301];
int dp[21][201];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
        cin >> day[i] >> page[i];

    for (int ci = 1; ci <= m; ++ci) // 순회필요한 것
    {
        for (int di = 1; di <= n; ++di) // 코스트
        {
            if (di >= day[ci])
            {
                dp[ci][di] = max(
                    dp[ci - 1][di],
                    dp[ci - 1][di - day[ci]] + page[ci]
                );
            }
            else
            {
                dp[ci][di] = dp[ci - 1][di];
            }
        }
    }

    cout << dp[m][n];
}