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

    cin >> n >> k;

    dp[0] = 1;

    int temp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        if (temp >= MAX_K) continue;
        
        for (int j = temp; j <= k; ++j)
            dp[j] += dp[j - temp];
    }

    cout << dp[k];
}