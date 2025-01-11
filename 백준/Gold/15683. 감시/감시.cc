#include <iostream>
#include <vector>
using namespace std;
int dy[4]{-1, 0, 1, 0 };
int dx[4]{ 0, 1, 0,-1 }; // 북 동 남 서

vector<vector<int>> map;
int height, width;

struct Cam
{
    int t;
    int y;
    int x;

    Cam(int _t, int _y, int _x) : y(_y), x(_x), t(_t) {}
};

vector<vector<pair<int, int>>> cameras; // 카메라 인덱스별 분류
vector<Cam> cams;
vector<int> camDir;
int camIdx;

int ret = INT32_MAX;

void Ray(vector<vector<int>>& _map, int y, int x, int dir)
{
    while (true)
    {
        y += dy[dir];
        x += dx[dir];

        if (y < 0 || y >= height || x < 0 || x >= width) break;
        if (_map[y][x] == 6) break;

        if (_map[y][x] == 0)
            _map[y][x] = 7;
    }
}

void Go(vector<vector<int>> _map, int ci)
{
    if (ci == cams.size())
    {
        int sum = 0;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (_map[y][x] == 0)
                    ++sum;
            }
        }

        if (sum < ret)
            ret = sum;

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        camDir[ci] = i;

        int type = cams[ci].t;
        int y = cams[ci].y;
        int x = cams[ci].x;

        vector<vector<int>> _origin = _map;

        if (type == 1)
        {
            Ray(_map, y, x, i);
        }
        else if (type == 2)
        {
            Ray(_map, y, x, i);
            Ray(_map, y, x, i + 2);
        }
        else if (type == 3)
        {
            Ray(_map, y, x, i);
            Ray(_map, y, x, (i + 1) % 4);
        }
        else if (type == 4)
        {
            Ray(_map, y, x, (i + 3) % 4);
            Ray(_map, y, x, i);
            Ray(_map, y, x, (i + 1) % 4);
        }
        else if (type == 5)
        {
            Ray(_map, y, x, i);
            Ray(_map, y, x, i + 1);
            Ray(_map, y, x, i + 2);
            Ray(_map, y, x, i + 3);
        }

        Go(_map, ci + 1);

        if (type == 5) break;// 5번캠은 1번만
        if (type == 2 && i == 1) break; // 2번 캠은 2번만

        // 복구
        _map = _origin;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    cams.reserve(8);
    cameras.resize(6);
    map.assign(height, vector<int>(width));
    int temp;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            cin >> temp;
            map[y][x] = temp;

            if (temp >= 1 && temp <= 5)
            {
                cameras[temp].push_back({ y, x });
                cams.push_back(Cam(temp, y, x));
            }
        }
    }

    camDir.resize(cams.size());

    // 5번 카메라는 방향이 없으니 무조건 진행
    for (int i = 0; i < cameras[5].size(); ++i)
    {
        int y = cameras[5][i].first;
        int x = cameras[5][i].second;

        for (int d = 0; d < 4; ++d)
            Ray(map, y, x, d);
    }

    Go(map, 0);

    cout << ret;
    return 0;
}