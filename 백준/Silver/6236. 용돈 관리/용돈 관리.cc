#include <iostream>
#include <vector>
using namespace std;

int n, m, ret = INT32_MAX;
vector<int> v;

bool Check(int mid)
{
    int money = mid;
    int cnt = 1;
    int overCnt = 0;

    for (int i = 0; i < n; ++i)
    {
        int require = v[i];
        if (require > money)
        {
            money = mid;
            ++cnt;

            if (cnt > m)
                return false;
        }

        if (money < require)
            return false;

        money -= require;
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