#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll x, y, z, r;

struct Point
{
    ll x, y, z;
    Point() : x(0), y(0), z(0) {}
    Point(ll x, ll y, ll z) : x(x), y(y), z(z) {}
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<Point> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        v[i] = Point(x, y, z);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z >> r;

        int cnt = 0;
        for (const Point& p : v)
        {
            if ((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y) + (p.z - z) * (p.z - z) <= r * r)
                ++cnt;
        }

        cout << cnt << '\n';
    }
}