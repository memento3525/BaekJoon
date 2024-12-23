#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int height, width;
vector<vector<int>> map;
vector<vector<int>> visited;

int dy[4] = { 0, 1, 0,-1 };
int dx[4] = { 1, 0,-1, 0 };
int maxDist = 0;

void BFS(int startY, int startX)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            visited[y][x] = 0;
    }

    queue<pair<int, int>> open;
    open.push({ startY, startX });
    visited[startY][startX] = 1;

    while (!open.empty())
    {
        const pair<int, int>& top = open.front();
        int y = top.first;
        int x = top.second;
        open.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= height) continue;
            if (nx < 0 || nx >= width) continue;
            if (map[ny][nx] == 1) continue;
            if (visited[ny][nx] != 0) continue;

            visited[ny][nx] = visited[y][x] + 1;

            open.push({ ny, nx });

            if (visited[ny][nx] > maxDist)
                maxDist = visited[ny][nx];
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    char temp;
    map.resize(height);
    visited.resize(height);
    for (int y = 0; y < height; ++y)
    {
        map[y].resize(width);
        visited[y].resize(width);
        for (int x = 0; x < width; ++x)
        {
            cin >> temp;
            map[y][x] = (temp == 'L') ? 0 : 1;
        }
    }

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (map[y][x] == 0)
                BFS(y, x);
        }
    }

    cout << maxDist - 1;
}