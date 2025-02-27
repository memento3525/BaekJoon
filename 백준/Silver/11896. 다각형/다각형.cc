#include <iostream>
using namespace std;
using ll = long long;

int main(void)
{
    ll a, b;
    cin >> a >> b;

    if (a & 1) ++a;

    ll sum = 0;
    for (ll i = a; i <= b; i += 2)
    {
        if (i == 2) continue;
        sum += i;
    };
    cout << sum;
}