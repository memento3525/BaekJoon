#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int ti = 0; ti < t; ++ti)
    {
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < m; ++i)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ret = 0;
        int canEatB = -1;
        for (int i = 0; i < n; ++i)
        {
            int left = max(canEatB, 0);
            int right = m - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (a[i] > b[mid])
                {
                    canEatB = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            ret += canEatB + 1;
        }

        cout << ret << '\n';
    }
}