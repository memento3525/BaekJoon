#include <iostream>
#include <vector>
using namespace std;

int n, m, ret;
vector<int> v;

bool Check(int size)
{
    int blueray = 1;
    int remain = size;

    for (int i : v)
    {
        if (remain < i)
        {
            ++blueray;

            if (blueray > m)
                return false;

            remain = size;
        }

        remain -= i;
        if (remain < 0)
            return false;
    }

    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    v.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int left = 1;
    int right = INT32_MAX;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (Check(mid))
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