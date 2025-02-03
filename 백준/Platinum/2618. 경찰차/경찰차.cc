#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, w;
int ay[1003];
int ax[1003];

int dp[1003][1003]; // a경찰차의 위치 인덱스, b경찰차의 위치 인덱스

int Dist(int a, int b)
{
    return abs(ay[a] - ay[b]) + abs(ax[a] - ax[b]);
}

int Go(int a, int b)
{
    if (a == w + 1 || b == w + 1) // 누군가 마지막 사건을 해결함
        return 0;

    if (dp[a][b])
        return dp[a][b];

    int next = max(a, b) + 1;
    return dp[a][b] = min(
        Go(a, next) + Dist(b, next), 
        Go(next, b) + Dist(a, next)
    );
}

void PrintTracking()
{
    int a = 0;
    int b = 1;
    for (int i = 2; i < w + 2; ++i)
    {
        if (dp[i][b] + Dist(a, i) < dp[a][i] + Dist(b, i))
        {
            cout << "1" << '\n';
            a = i;
        }
        else
        {
            cout << "2" << '\n';
            b = i;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    ay[0] = 1; ax[0] = 1;
    ay[1] = n; ax[1] = n;

    for (int i = 2; i < w + 2; ++i)
        cin >> ay[i] >> ax[i];

    cout << Go(0, 1) << '\n';
    PrintTracking();
}