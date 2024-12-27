#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { 0, 1, 0,-1 };
int dx[4] = { 1, 0,-1, 0 };
int height, width, k, targetY, targetX;;
vector<string> map;
vector<vector<int>> visited;

int Go(int y, int x)
{
    if (y == targetY && x == targetX)
    {
        if (k == visited[y][x])
            return 1;
        else
            return 0;
    }

    int ret = 0;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
        if (visited[ny][nx]) continue;
        if (map[ny][nx] == 'T') continue;

        visited[ny][nx] = visited[y][x] + 1;
        ret += Go(ny, nx);
        visited[ny][nx] = 0;
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> k;

    targetY = 0;
    targetX = width - 1;

    map.resize(height);
    visited.resize(height);
    for (int y = 0; y < height; ++y)
    {
        visited[y].resize(width);
        cin >> map[y];
    }

    visited[height - 1][0] = 1;
    
    int ret = Go(height - 1, 0);
    cout << ret;
}