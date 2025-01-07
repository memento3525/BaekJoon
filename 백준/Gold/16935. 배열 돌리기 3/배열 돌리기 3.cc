#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4]{ 1, 0,-1, 0 };
int dx[4]{ 0, 1, 0,-1 };

int height, width, r;
vector<vector<int>> map;
vector<vector<int>> rotMap;
int ret = INT32_MAX;

bool isA = true;

const int Height() { return isA ? height : width; }
const int Width() { return isA ? width : height; }
vector<vector<int>>& CurMap() { return isA ? map : rotMap; }
vector<vector<int>>& OtherMap() { return isA ? rotMap : map; }

void Print()
{
    auto& cur = CurMap();
    for (int y = 0; y < Height(); ++y)
    {
        for (int x = 0; x < Width(); ++x)
            cout << cur[y][x] << " ";
        cout << '\n';
    }
}

void _1()
{
    auto& cur = CurMap();
    for (int x = 0; x < Width(); ++x)
    {
        for (int y = 0; y < Height() / 2; ++y)
            swap(cur[y][x], cur[Height() - y - 1][x]);
    }
}

void _2()
{
    auto& cur = CurMap();
    for (int y = 0; y < Height(); ++y)
    {
        for (int x = 0; x < Width() / 2; ++x)
            swap(cur[y][x], cur[y][Width() - x - 1]);
    }
}
void _3()
{
    auto& cur = CurMap();
    auto& other = OtherMap();
    for (int y = 0; y < Height(); ++y)
    {
        for (int x = 0; x < Width(); ++x)
            other[x][Height() - y - 1] = cur[y][x];
    }
    isA = !isA;
}
void _4()
{
    auto& cur = CurMap();
    auto& other = OtherMap();
    for (int y = 0; y < Height(); ++y)
    {
        for (int x = 0; x < Width(); ++x)
            other[Width() - x - 1][y] = cur[y][x];
    }
    isA = !isA;
}
void _5()
{
    auto& cur = CurMap();

    int halfHeight = Height() / 2;
    int halfWidth = Width() / 2;
    for (int y = 0; y < Height(); ++y)
    {
        for (int x = 0; x < halfWidth; ++x)
            swap(cur[y][x], cur[y][x + halfWidth]);
    }

    for (int y = 0; y < halfHeight; ++y)
    {
        for (int x = 0; x < halfWidth; ++x)
            swap(cur[y][x], cur[y + halfHeight][x + halfWidth]);
    }
}

void _6()
{
    auto& cur = CurMap();

    int halfHeight = Height() / 2;
    int halfWidth = Width() / 2;
    for (int x = 0; x < Width(); ++x)
    {
        for (int y = 0; y < halfHeight; ++y)
            swap(cur[y][x], cur[y + halfHeight][x]);
    }

    for (int y = 0; y < halfHeight; ++y)
    {
        for (int x = 0; x < halfWidth; ++x)
            swap(cur[y][x], cur[y + halfHeight][x + halfWidth]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> r;

    map.assign(height, vector<int>(width));
    rotMap.assign(width, vector<int>(height));

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            cin >> map[y][x];
    }

    typedef void(*Cmp)();
    Cmp cmp[6]{ _1, _2, _3, _4, _5, _6 };

    int i;
    while (cin >> i)
        cmp[i - 1]();

    Print();
}