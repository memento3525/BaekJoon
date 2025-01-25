#include <iostream>
#include <vector>
using namespace std;

const int mod = 1'000'007;
int height, width, c;

int map[51][51];
int dp[51][51][51][51]; // y, x, 방문횟수, 오락실인덱스

int Go(int y, int x, int cnt, int prevIndex)
{
    if (y > height || x > width) return 0;
    if (y == height && x == width)
    {
        if (cnt == 0 && map[y][x] == 0) return 1;
        if (cnt == 1 && map[y][x] > prevIndex) return 1;
        return 0;
    }

    int& ret = dp[y][x][cnt][prevIndex];
    if (ret != -1) return ret;

    ret = 0;

    int pos = map[y][x];
    if (pos == 0)
        ret = (Go(y + 1, x, cnt, prevIndex) + Go(y, x + 1, cnt, prevIndex)) % mod;
    else if (pos > prevIndex)
        ret = (Go(y + 1, x, cnt - 1, pos) + Go(y, x + 1, cnt - 1, pos)) % mod;

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0][0][0], &dp[0][0][0][0] + 51 * 51 * 51 * 51, -1); // 6,765,201

    cin >> height >> width >> c;

    int y, x;
    for (int i = 1; i <= c; ++i)
    {
        cin >> y >> x;
        map[y][x] = i;
    }

    for (int i = 0; i <= c; ++i)
        cout << Go(1, 1, i, 0) << '\n';
}