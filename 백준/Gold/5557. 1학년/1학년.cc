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
    if (here == n - 1)
        return (sum == num[n - 1]);

    ll& ret = dp[here][sum];
    if (ret != -1) return ret;

    ret = 0;

    if (sum + num[here] <= 20)
        ret += Go(here + 1, sum + num[here]);

    if (sum - num[here] >= 0)
        ret += Go(here + 1, sum - num[here]);

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

    cout << Go(1, num[0]);
}