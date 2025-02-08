#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n;
int a[101];
int b[101];
int dp[101][10][10][10][2];

int _mod(int i)
{
    return (i + 10) % 10;
}

// 확인하는 인덱스, 각 수를 돌린offset, 방향(시계/반시계)
int Go(int pos, int x, int y, int z, int dir)
{
    if (pos == n)
        return 0;

    int& ret = dp[pos][x][y][z][dir];
    if (ret != -1) return ret;

    // 같다면 pos를 하나 증가
    if (_mod(x + a[pos]) == _mod(b[pos]))
    {
        ret = min(Go(pos + 1, y, z, 0, 0), Go(pos + 1, y, z, 0, 1));
        return ret;
    }

    // 같지않다면 1~3칸을 1~3개랑 동시에 돌리는 경우 : 9가지를 다 체크
    ret = INF;
    for (int i = 1; i <= 3; ++i)
    {
        int move = dir ? i : -i;
        ret = min(ret, 1 + Go(pos, _mod(x + move),              y,              z, dir));
        ret = min(ret, 1 + Go(pos, _mod(x + move), _mod(y + move),              z, dir));
        ret = min(ret, 1 + Go(pos, _mod(x + move), _mod(y + move), _mod(z + move), dir));
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0] + 101 * 10 * 10 * 10 * 2, -1);

    cin >> n;

    string temp;

    cin >> temp;
    for (int i = 0; i < n; ++i)
        a[i] = temp[i];

    cin >> temp;
    for (int i = 0; i < n; ++i)
        b[i] = temp[i];

    cout << min(Go(0, 0, 0, 0, 0), Go(0, 0, 0, 0, 1));
}