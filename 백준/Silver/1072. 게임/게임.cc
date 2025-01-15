#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll x, y, z;

int main(void)
{
    cin >> x >> y;

    if (x == y)
    {
        cout << "-1";
        return 0;
    }

    z = y * 100LL / x;

    int left = 0;
    int right = 1'000'000'000;
    int ret = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (z + 1 <= (y + mid) * 100LL / (x + mid))
        {
            ret = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ret;
}