#include <iostream>
#include <vector>
using namespace std;
int dy[4]{ 0,-1, 0, 1 };
int dx[4]{ 1, 0,-1, 0 };

int rdy[4]{ 0, 1, 0,-1 };
int rdx[4]{ 1, 0,-1, 0 };

int height, width, t, airY_Up, airY_Down;
vector<vector<int>> mapA;
vector<vector<int>> mapB;
bool _isA = false;

void Diffusion()
{
    auto& curMap = _isA ? mapA : mapB;
    auto& nextMap = _isA ? mapB : mapA;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            nextMap[y][x] = 0;
    }

    nextMap[airY_Up][0] = -1;
    nextMap[airY_Down][0] = -1;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (curMap[y][x] == -1) continue;

            int mass = curMap[y][x] / 5;
            int cnt = 0;

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= height) continue;
                if (nx < 0 || nx >= width) continue;
                if (curMap[ny][nx] == -1) continue;

                nextMap[ny][nx] += mass;
                ++cnt;
            }

            nextMap[y][x] += curMap[y][x] - mass * cnt;
        }
    }
}

void Air(int airY, int* ddy, int* ddx)
{
    auto& nextMap = _isA ? mapB : mapA;

    int cur = 0;
    int y = airY;
    int x = 0;
    int dir = 0;

    while (true)
    {
        int ny = y + ddy[dir];
        int nx = x + ddx[dir];

        if (ny < 0 || ny >= height || nx < 0 || nx >= width)
        {
            ++dir;
            continue;
        }

        if (nextMap[ny][nx] == -1)
            break;

        swap(nextMap[ny][nx], cur);
        y = ny;
        x = nx;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> t;

    mapA.resize(height);
    mapB.resize(height);
    for (int y = 0; y < height; ++y)
    {
        mapA[y].resize(width);
        mapB[y].resize(width);
        for (int x = 0; x < width; ++x)
            cin >> mapA[y][x];
    }

    for (int y = 0; y < height; ++y)
    {
        if (mapA[y][0] == -1)
        {
            airY_Up = y;
            airY_Down = y + 1;
            break;
        }
    }

    while (t > 0)
    {
        --t;
        _isA = !_isA;

        Diffusion();
        Air(airY_Up, dy, dx);
        Air(airY_Down, rdy, rdx);
    }

    auto& nextMap = _isA ? mapB : mapA;
    int ret = 2;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            ret += nextMap[y][x];
    }

    cout << ret;
}