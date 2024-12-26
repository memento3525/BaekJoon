#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> map;
vector<int> visited;

int height, width, result;
int dy[4] = { 0, 1, 0,-1 };
int dx[4] = { 1, 0,-1, 0 };

void Move(int y, int x, int cnt)
{
    if (cnt > result)
        result = cnt;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= height) continue;
        if (nx < 0 || nx >= width) continue;

        int charIndex = map[ny][nx] - 'A';
        if (visited[charIndex] == 1) continue;

        visited[charIndex] = 1;
        Move(ny, nx, cnt + 1);
        visited[charIndex] = 0;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    map.resize(height);
    for (int y = 0; y < height; ++y)
    {
        map[y].resize(width);
        for (int x = 0; x < width; ++x)
            cin >> map[y][x];
    }

    visited.resize('Z' - 'A');
    visited[map[0][0] - 'A'] = 1;

    Move(0, 0, 1);

    cout << result;
}