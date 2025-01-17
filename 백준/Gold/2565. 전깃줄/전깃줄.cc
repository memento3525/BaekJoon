#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    int a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        v[i] = { a, b };
    }

    sort(v.begin(), v.end());

    int len = 0;
    vector<int> vv(n, 501);
    for (int i = 0; i < n; ++i)
    {
        int temp = v[i].second;

        auto lowerPos = lower_bound(vv.begin(), vv.end(), temp);
        if (*lowerPos == 501)
            ++len;

        *lowerPos = temp;
    }

    cout << (n - len);
}