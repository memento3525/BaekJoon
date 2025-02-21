#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll x, y, z, r;
ll ax[100001], ay[100001], az[100001], ar[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> ax[i] >> ay[i] >> az[i];

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z >> r;

        ll rr = r * r;
        int cnt = 0;
        for (int k = 0; k < n; ++k)
        {
            ll dx = (ax[k] - x);
            ll dy = (ay[k] - y);
            ll dz = (az[k] - z);

            if (dx * dx + dy * dy + dz * dz <= rr)
                ++cnt;
        }

        cout << cnt << '\n';
    }
}