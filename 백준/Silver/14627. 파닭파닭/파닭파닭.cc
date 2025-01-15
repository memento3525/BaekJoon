#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll s, c;
vector<ll> v;

bool Check(ll mid)
{
    ll cnt = 0;
    for (ll i : v)
    {
        if (i < mid) continue;

        cnt += i / mid;
        if (cnt >= c)
            return true;
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> c;

    v.resize(c);
    for (int i = 0; i < c; ++i)
        cin >> v[i];

    ll left = 1;
    ll right = 1'000'000'000;
    ll len = 0;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (Check(mid))
        {
            len = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    ll ret = 0;
    for (ll i : v)
        ret += (i - len);

    cout << ret;
}