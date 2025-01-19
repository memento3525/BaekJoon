#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int map[16][16];
int dp[16][16][3];

bool Can(int y, int x, int dir)
{
    if (y >= n || x >= n) return false;
    if (map[y][x] == 1) return false;
    if (dir == 1) // 대각선
    {
        if (map[y - 1][x] == 1) return false;
        if (map[y][x - 1] == 1) return false;
    }

    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            cin >> map[y][x];
    }

    dp[0][1][0] = 1; // 시작

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            // 가로(0)에서 온 경우
            if (Can(y, x + 1, 0))
                dp[y][x + 1][0] += dp[y][x][0];
            if (Can(y + 1, x + 1, 1)) 
                dp[y + 1][x + 1][1] += dp[y][x][0];

            // 대각선(1)에서 온 경우
            if (Can(y, x + 1, 0)) 
                dp[y][x + 1][0] += dp[y][x][1];
            if (Can(y + 1, x + 1, 1)) 
                dp[y + 1][x + 1][1] += dp[y][x][1];
            if (Can(y + 1, x, 2)) 
                dp[y + 1][x][2] += dp[y][x][1];

            // 세로(2)에서 온 경우
            if (Can(y + 1, x + 1, 1)) 
                dp[y + 1][x + 1][1] += dp[y][x][2];
            if (Can(y + 1, x, 2))
                dp[y + 1][x][2] += dp[y][x][2];
        }
    }

    int ret = dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
    cout << ret;
}