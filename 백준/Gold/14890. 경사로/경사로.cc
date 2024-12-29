#include <iostream>
#include <vector>
using namespace std;

int n, l, ret;
vector<vector<int>> map;
vector<vector<int>> map2;

int IsValid(const vector<int>& v)
{
    int cnt = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int cur = v[i];
        int next = v[i + 1];
        if (cur == next)
        {
            ++cnt;
        }
        else
        {
            if (cur + 1 == next)
            {
                if (cnt >= l)
                {
                    cnt = 1;
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            else if (cur - 1 == next && cnt >= 0)
            {
                cnt = -l + 1;
                continue;
            }
            else // 2차이
            {
                return 0;
            }
        }
    }

    return (cnt >= 0) ? 1 : 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;

    map.resize(n);
    map2.resize(n);
    for (int y = 0; y < n; ++y)
    {
        map[y].resize(n);
        map2[y].resize(n);
        for (int x = 0; x < n; ++x)
            cin >> map[y][x];
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            map2[x][y] = map[y][x];
    }

    for (int y = 0; y < n; ++y)
    {
        ret += IsValid(map[y]);
        ret += IsValid(map2[y]);
    }

    cout << ret;
}