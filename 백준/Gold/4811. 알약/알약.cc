#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n;
ll dp[31][31];

ll Go(int a, int b)
{
    if (a == 0 && b == 0) return 1;

    ll& ret = dp[a][b];
    if (ret != 0) return ret;

    if (a > 0)
        ret += Go(a - 1, b + 1);

    if (b > 0)
        ret += Go(a, b - 1);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n)
    {
        if (n == 0) break;
        cout << (Go(n, 0)) << '\n';
    }
}