#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

map<ll, ll> fmap;

ll Go(ll n)
{
    if (fmap.find(n) != fmap.end())
        return fmap[n];

    fmap[n] = min(
        Go(n / 3) + (n % 3),
        Go(n / 2) + (n % 2)
    ) + 1;

    return fmap[n];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    fmap[1] = 0;
    fmap[2] = 1;

    cout << Go(n);
}