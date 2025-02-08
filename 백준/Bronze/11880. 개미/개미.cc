#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using ll = long long;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    ll a, b, c;
    while (t--)
    {
        cin >> a >> b >> c;
        ll aa = (a * a) + ((b + c) * (b + c));
        ll bb = (b * b) + ((a + c) * (a + c));
        ll cc = (c * c) + ((b + a) * (b + a));
        cout << (min(min(aa, bb), cc)) << '\n';
    }
}