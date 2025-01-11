#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m, t, sum, cnt;

vector<vector<int>> v;

void AfterRotate()
{
    set<pair<int, int>> deleted;

    for (int x = 0; x < m; ++x)
    {
        for (int y = 0; y < n - 1; ++y)
        {
            if (v[y][x] == 0) continue;

            int ny = y + 1;
            if (v[y][x] == v[ny][x])
            {
                deleted.insert({ y, x });
                deleted.insert({ ny, x });
            }
        }
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            if (v[y][x] == 0) continue;

            int nx = (x + 1) % m;
            if (v[y][x] == v[y][nx])
            {
                deleted.insert({ y, x });
                deleted.insert({ y, nx });
            }
        }
    }

    if (deleted.size())
    {
        cnt -= deleted.size();

        for (const auto& item : deleted)
        {
            sum -= v[item.first][item.second];
            v[item.first][item.second] = 0;
        }
    }
    else
    {
        float av = ((float)sum / cnt);
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < m; ++x)
            {
                if (v[y][x] == 0) continue;

                float fv = (float)v[y][x];
                if (fv > av)
                {
                    --v[y][x];
                    --sum;
                }
                else if (fv < av)
                {
                    ++v[y][x];
                    ++sum;
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t;

    v.assign(n, vector<int>(m));
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            cin >> v[y][x];
            sum += v[y][x];
            ++cnt;
        }
    }

    int xi, di, ki;
    for (int i = 0; i < t; ++i)
    {
        cin >> xi >> di >> ki;

        // 회전 진행
        for (int y = xi; y < n + 1; y += xi)
        {
            vector<int>& a = v[y - 1];
            if (di == 0) // 시계방향
                rotate(a.begin(), a.end() - ki, a.end());
            else // 반시계
                rotate(a.begin(), a.begin() + ki, a.end());
        }
        AfterRotate();
    }

    cout << sum;
    return 0;
}