#include <iostream>
#include <vector>
using namespace std;

int n, k;
int dp[101][100001];

int walk[101];
int bike[101];
int walk_t[101];
int bike_t[101];

int Go(int idx, int time)
{
    if (idx == n) return 0;

    int& ret = dp[idx][time];
    if (ret > 0) return ret;

    ret = -1e6;

    if (time >= walk_t[idx])
        ret = max(ret, Go(idx + 1, time - walk_t[idx]) + walk[idx]);

    if (time >= bike_t[idx])
        ret = max(ret, Go(idx + 1, time - bike_t[idx]) + bike[idx]);

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k; // n은 도시갯수, k는 최대시간

    for (int i = 0; i < n; ++i)
        cin >> walk_t[i] >> walk[i] >> bike_t[i] >> bike[i];

    cout << Go(0, k);
}