#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
vector<vector<int>> tempMap;

int ret = INT32_MIN;

void Rotate90() // x축 반전하고 + 전치
{
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            tempMap[y][x] = map[n - x - 1][y];
    }

    map = tempMap;
}

void _Move()
{
    // +x방향움직임
    for (int y = 0; y < n; ++y)
    {
        int cur = 0;
        int index = 0;

        for (int x = 0; x < n; ++x)
        {
            if (map[y][x] == 0) continue;

            if (cur == 0)
            {
                cur = map[y][x];
                map[y][x] = 0;
            }
            else if (cur == map[y][x])
            {
                map[y][x] = 0;
                map[y][index++] = 2 * cur;
                cur = 0;
            }
            else // 값이 있는데 다름
            {
                map[y][index++] = cur;
                cur = map[y][x];
                map[y][x] = 0;
            }
        }

        if (cur != 0)
            map[y][index] = cur;
    }
}

void Go(int cnt)
{
    if (cnt == 5)
    {
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (map[y][x] > ret)
                    ret = map[y][x];
            }
        }
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        vector<vector<int>> origin = map;

        for (int k = 0; k < i; ++k)
            Rotate90();

        _Move();

        Go(cnt + 1);
        map = origin;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    map.resize(n);
    tempMap.resize(n);
    for (int y = 0; y < n; ++y)
    {
        map[y].resize(n);
        tempMap[y].resize(n);
        for (int x = 0; x < n; ++x)
            cin >> map[y][x];
    }
    
    Go(0);

    cout << ret;
}