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
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[i] = { a , b };
    }

    sort(v.begin(), v.end());

    int left = -1'000'000'000;
    int ret = 0;
    for (const auto& i : v)
    {
        int a = i.first;
        int b = i.second;

        if (b < left)
            continue;

        left = max(left, a);

        ret += (b - left);
        left = b;
    }

    cout << ret;
}