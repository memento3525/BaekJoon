#include <iostream>
#include <vector>
using namespace std;

int height, width;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> v;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void DFS(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= height) continue;
        if (nx < 0 || nx >= width) continue;
        if (visited[ny][nx]) continue;
        if (map[ny][nx] == 1)
        {
            v.push_back({ ny, nx });
            continue;
        }

        DFS(ny, nx);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    map.resize(height);
    visited.resize(height);

    int temp;
    for (int y = 0; y < height; ++y)
    {
        map[y] = vector<int>(width);
        visited[y] = vector<bool>(width);
        for (int x = 0; x < width; ++x)
        {
            cin >> temp;
            map[y][x] = temp;
        }
    }

    int prevCheese = 0;
    int time = 0;
    while (true)
    {
        DFS(0, 0);

        int cheese = 0;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (map[y][x] == 1)
                    ++cheese;
            }
        }

        if (cheese == 0)
            break;

        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
                visited[y][x] = false;
        }

        for (const auto& item : v)
            map[item.first][item.second] = 0;

        v.clear();

        prevCheese = cheese;
        ++time;
    }

    cout << time << '\n' << prevCheese;
}