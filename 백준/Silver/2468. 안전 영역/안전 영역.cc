#include <iostream>
#include <vector>
using namespace std;

int n, k, currentSink;
vector<vector<int>> map;
vector<vector<bool>> visited;

int dirY[4] = { 1, 0, -1,  0 };
int dirX[4] = { 0, 1,  0, -1 };

void DFS(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dirY[i];
        int nx = x + dirX[i];

        if (ny < 0 || ny >= n) continue;
        if (nx < 0 || nx >= n) continue;

        if (map[ny][nx] > currentSink && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            DFS(ny, nx);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    map.resize(n);
    visited.resize(n);

    int temp;
    int maxHeight = 0;
    for (int y = 0; y < n; ++y)
    {
        map[y] = vector<int>(n);
        visited[y] = vector<bool>(n);

        for (int x = 0; x < n; ++x)
        {
            cin >> temp;
            map[y][x] = temp;

            if (temp > maxHeight)
                maxHeight = temp;
        }
    }

    int maxSinkCount = 1;

    for (int sink = 1; sink < maxHeight; ++sink)
    {
        currentSink = sink;

        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
                visited[y][x] = false;
        }

        int count = 0;
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (map[y][x] > currentSink && !visited[y][x])
                {
                    DFS(y, x);
                    ++count;
                }
            }
        }

        if (count > maxSinkCount)
            maxSinkCount = count;
    }

    cout << maxSinkCount;
}