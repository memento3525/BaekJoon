#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    vector<int> dp(n, 0);
    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max(v[0], v[1]) + v[2];

    for (int i = 3; i < n; ++i)
    {
        dp[i] = max(dp[i - 3] + v[i - 1], dp[i - 2]) + v[i];
    }
    
    cout << dp[n - 1];
}