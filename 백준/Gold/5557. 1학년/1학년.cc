#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int n;
ll num[102];
ll dp[102][21];

const ll MINUS = 0;
const ll PLUS = 1;

ll Go(ll here, ll sum)
{
    if (sum < 0 || sum > 20) return 0;

    if (here == n - 2)
        return (sum == num[n - 1]);

    ll& ret = dp[here][sum];
    if (ret != -1) return ret;

    ret = Go(here + 1, sum + num[here + 1]) 
        + Go(here + 1, sum - num[here + 1]);

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0], &dp[0][0] + 102 * 21, -1);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> num[i];

    cout << Go(0, num[0]);
}