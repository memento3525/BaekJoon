#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

ll N, P, Q;
map<ll, ll> dp;

ll Go(ll n)
{
    if (n == 0) return 1;

    if (dp[n] != 0)
        return dp[n];

    dp[n] = Go(n / P) + Go(n / Q);
    return dp[n];
}

int main(void)
{
    cin >> N >> P >> Q;
    cout << Go(N);
}