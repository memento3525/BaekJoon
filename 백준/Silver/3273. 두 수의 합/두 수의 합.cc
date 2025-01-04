#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cin >> x;

    sort(v.begin(), v.end());

    int l = 0;
    int r = n - 1;

    int ret = 0;
    while (l < r)
    {
        int sum = v[l] + v[r];

        if (sum < x)
        {
            ++l;
        }
        else if (sum > x)
        {
            --r;
        }
        else if (sum == x)
        {
            ++l;
            ++ret;
        };
    }

    cout << ret;
}