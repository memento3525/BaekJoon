#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height, width, k;
vector<vector<bool>> map;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void DFS(int y, int x, int& area)
{
    map[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= height) continue;
        if (nx < 0 || nx >= width) continue;

        if (!map[ny][nx])
        {
            ++area;
            DFS(ny, nx, area);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> k;

    // 맵 초기화
    map = vector<vector<bool>>(height);
    for (int y = 0; y < height; ++y)
    {
        map[y] = vector<bool>(width);
    }

    // 맵 설정
    int x1, y1, x2, y2;
    for (int i = 0; i < k; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; ++y)
        {
            for (int x = x1; x < x2; ++x)
            {
                map[y][x] = true;
            }
        }
    }

    // 계산
    int result = 0;
    vector<int> areas;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (!map[y][x])
            {
                int area = 1;
                DFS(y, x, area);
                ++result;
                areas.emplace_back(area);
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << result << '\n';

    for (const int& i : areas)
    {
        cout << i << " ";
    }
}