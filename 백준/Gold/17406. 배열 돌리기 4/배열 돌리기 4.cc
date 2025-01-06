#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4]{ 0, 1, 0,-1 };
int dx[4]{ 1, 0,-1, 0 };

int height, width, k;
vector<vector<int>> map;
vector<vector<int>> backup;
int ret = INT32_MAX;

void _Rotate(int y, int x, int length)
{
    int cur = map[y][x];
    int i = 0;
    int step = length;
    while (i < 4)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        swap(cur, map[ny][nx]);

        --step;
        if (step == 0)
        {
            ++i;
            step = length;
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

    cin >> height >> width >> k;

    map.assign(height, vector<int>(width));

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            cin >> map[y][x];
    }
    backup = map;

    vector<vector<int>> methods(k);
    for (int i = 0; i < k; ++i)
    {
        int r, c, s;
        cin >> r >> c >> s;
        methods[i] = {r - 1, c - 1, s};
    }

    vector<int> indexes(k);
    for (int i = 0; i < k; ++i)
        indexes[i] = i;

    do
    {
        map = backup;
        
        for (int i = 0; i < k; ++i)
        {
            const vector<int>& method = methods[indexes[i]];
            int r = method[0];
            int c = method[1];
            int s = method[2];

            for (int k = 0; k < s; ++k)
                _Rotate(r - s + k, c - s + k, 2 * (s - k));
        }

        for (int y = 0; y < height; ++y)
        {
            int xSum = 0;
            for (int x = 0; x < width; ++x)
                xSum += map[y][x];

            if (xSum < ret)
                ret = xSum;
        }

    } while (next_permutation(indexes.begin(), indexes.end()));

    cout << ret;
}