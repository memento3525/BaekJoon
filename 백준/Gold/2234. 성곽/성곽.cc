#include <iostream>
#include <vector>
using namespace std;

int height, width;
vector<vector<int>> map;
vector<vector<int>> visited;
vector<int> sizes;

int bigSize;
int dy[4]{  0,-1, 0, 1 };
int dx[4]{ -1, 0, 1, 0 };
int ww[4]{  1, 2, 4, 8 };

int BFS(int y, int x, int type)
{
    int sum = 1;

    for (int i = 0; i < 4; ++i)
    {
        if (map[y][x] & ww[i]) continue;

        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= height) continue;
        if (nx < 0 || nx >= width) continue;
        if (visited[ny][nx]) continue;

        visited[ny][nx] = type;
        sum += BFS(ny, nx, type);
    }

    return sum;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> width >> height;

    map.resize(height);
    visited.resize(height);
    for (int y = 0; y < height; ++y)
    {
        map[y].resize(width);
        visited[y].resize(width);
        for (int x = 0; x < width; ++x)
        {
            cin >> map[y][x];
        }
    }

    int type = 1;
    sizes.emplace_back(0);
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (visited[y][x] == 0)
            {
                visited[y][x] = type;
                int size = BFS(y, x, type);
                if (size > bigSize)
                    bigSize = size;

                sizes.emplace_back(size);
                ++type;
            }
        }
    }

    int mergeSum = 0;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int typeA = visited[y][x];

            for (int i = 0; i < 4; ++i)
            {
                if (map[y][x] & ww[i])
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (ny < 0 || ny >= height) continue;
                    if (nx < 0 || nx >= width) continue;

                    int typeB = visited[ny][nx];

                    if (typeA != typeB)
                    {
                        int sum = sizes[typeA] + sizes[typeB];
                        if (sum > mergeSum)
                            mergeSum = sum;
                    }
                }
            }
        }
    }

    cout << type - 1 << '\n' << bigSize << '\n' << mergeSum;
}