#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, a, b;
    cin >> N >> L;

    int cur = 0;
    int ret = 0;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        v[i] = { a, b };
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i)
    {
        if (cur < v[i].first)
            cur = v[i].first;

        while (cur < v[i].second)
        {
            cur += L;
            ++ret;
        }
    }

    cout << ret;
}