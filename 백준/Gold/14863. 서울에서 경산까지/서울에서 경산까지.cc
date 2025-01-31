#include <iostream>
#include <vector>
using namespace std;

const int INF = (int)1e9;
int n, k;
int dp[101][100001];

int a[101], at[101];
int b[101], bt[101];

int Go(int idx, int time)
{
    if (time < 0) return -INF;
    if (idx == n) return 0;

    int& ret = dp[idx][time];
    if (ret != -INF) return ret;

    ret = max(
        Go(idx + 1, time - at[idx]) + a[idx], 
        Go(idx + 1, time - bt[idx]) + b[idx]
    );

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0], &dp[0][0] + 101 * 100001, -INF); // 끝까지 도달하지 못한 경로를 배제하기 위한 수

    cin >> n >> k; // n은 도시갯수, k는 최대시간

    for (int i = 0; i < n; ++i)
        cin >> at[i] >> a[i] >> bt[i] >> b[i];

    cout << Go(0, k);
}