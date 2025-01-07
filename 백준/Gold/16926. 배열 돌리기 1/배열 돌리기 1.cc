#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4]{ 1, 0,-1, 0 };
int dx[4]{ 0, 1, 0,-1 };

int height, width, r;
vector<vector<int>> map;
int ret = INT32_MAX;

void _Rotate(int y, int x, int yStep, int xStep)
{
    int cur = map[y][x];
    int i = 0;
    int step = yStep;
    while (i < 4)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        swap(cur, map[ny][nx]);

        --step;
        if (step == 0)
        {
            ++i;
            step = (dy[i] != 0) ? yStep : xStep;
        }

        y = ny;
        x = nx;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> r;

    map.assign(height, vector<int>(width));

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            cin >> map[y][x];
    }

    int maxK = min(width / 2, height / 2);
    for (int k = 0; k < maxK; ++k)
    {
        int yStep = height - k * 2 - 1;
        int xStep = width - k * 2 - 1;

        int rot = r % (2 * yStep + 2 * xStep);

        for (int i = 0; i < rot; ++i)
            _Rotate(0 + k, 0 + k, yStep, xStep);
    }

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            cout << map[y][x] << " ";
        cout << '\n';
    }
}