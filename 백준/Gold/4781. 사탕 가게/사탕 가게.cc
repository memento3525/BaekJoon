#include <iostream>
#include <vector>
using namespace std;

const int MAX_K = 10001;
const int INF = 1e9;

int dp[MAX_K];
int n, k;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    float tempFloat;
    int c, p;

    while (cin >> n)
    {
        if (n == 0) break;

        fill(dp, dp + MAX_K, 0);

        cin >> tempFloat;
        k = (int)(tempFloat * 100 + 0.5f);

        for (int i = 0; i < n; ++i)
        {
            cin >> c >> tempFloat;
            p = (int)(tempFloat * 100);

            if (c == 0) break;

            for (int j = p; j <= k; ++j)
            {
                dp[j] = max(
                    dp[j], // 이전꺼 그냥 쓴 경우
                    dp[j - p] + c); // 이전꺼 대신 이거 쓴 경우
            }
        }

        cout << dp[k] << '\n';
    }
}