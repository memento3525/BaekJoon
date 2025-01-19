#include <iostream>
#include <vector>
using namespace std;

int dy[4]{ -1, 0, 1, 0 };
int dx[4]{ 0, 1, 0,-1 };

int height, width;
vector<string> map;
int dp[50][50];
int visited[50][50];

int Go(int y, int x)
{
    if (y < 0 || x < 0 || y >= height || x >= width || map[y][x] == 'H')
        return 0;

    if (visited[y][x])
    {
        cout << "-1";
        exit(0);
    }

    int& ret = dp[y][x];
    if (ret != 0) return ret;

    visited[y][x] = 1;

    int num = map[y][x] - '0';
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i] * num;
        int nx = x + dx[i] * num;
        ret = max(ret, Go(ny, nx) + 1);
    }

    visited[y][x] = 0;
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    map.resize(height);
    for (int y = 0; y < height; ++y)
        cin >> map[y];

    cout << Go(0, 0);
}
