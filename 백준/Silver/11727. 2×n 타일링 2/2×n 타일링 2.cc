#include <iostream>
using namespace std;

int dp[1001];

int main(void)
{
    int n;
    cin >> n;
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    int k = 10007;

    for (int i = 3; i <= n; ++i)
        dp[i] = ((2 * dp[i - 2]) % k + dp[i - 1] % k) % k;

    cout << dp[n];
}