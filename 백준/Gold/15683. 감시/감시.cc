#include <iostream>
#include <vector>
using namespace std;
int dy[4]{-1, 0, 1, 0 };
int dx[4]{ 0, 1, 0,-1 };

vector<vector<int>> map;
int height, width;

struct Cam
{
    int t;
    int y;
    int x;

    Cam(int _t, int _y, int _x) : y(_y), x(_x), t(_t) {}
};

vector<Cam> cams;
vector<pair<int, int>> changed;

int ret = INT32_MAX;

void Ray(int y, int x, int dir)
{
    while (true)
    {
        y += dy[dir];
        x += dx[dir];

        if (y < 0 || y >= height || x < 0 || x >= width) break;
        if (map[y][x] == 6) break;

        if (map[y][x] == 0)
        {
            map[y][x] = 7;
            changed.push_back({ y, x });
        }
    }
}

void Go(int ci)
{
    if (ci == cams.size())
    {
        int sum = 0;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (map[y][x] == 0)
                    ++sum;
            }
        }

        if (sum < ret)
            ret = sum;

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int type = cams[ci].t;
        int y = cams[ci].y;
        int x = cams[ci].x;

        changed.clear();

        if (type == 1)
        {
            Ray(y, x, i);
        }
        else if (type == 2)
        {
            Ray(y, x, i);
            Ray(y, x, i + 2);
        }
        else if (type == 3)
        {
            Ray(y, x, i);
            Ray(y, x, (i + 1) % 4);
        }
        else if (type == 4)
        {
            Ray(y, x, (i + 3) % 4);
            Ray(y, x, i);
            Ray(y, x, (i + 1) % 4);
        }
        else if (type == 5)
        {
            Ray(y, x, i);
            Ray(y, x, i + 1);
            Ray(y, x, i + 2);
            Ray(y, x, i + 3);
        }

        vector<pair<int, int>> cachedChanged = changed;

        Go(ci + 1);

        // 복구
        for (const auto& pair : cachedChanged)
            map[pair.first][pair.second] = 0;

        if (type == 5) break; // 5번 캠은 1번만
        if (type == 2 && i == 1) break; // 2번 캠은 2번만
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    cams.reserve(8);
    map.assign(height, vector<int>(width));
    int temp;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            cin >> temp;
            map[y][x] = temp;

            if (temp >= 1 && temp <= 5)
                cams.push_back(Cam(temp, y, x));
        }
    }

    Go(0);

    cout << ret;
}