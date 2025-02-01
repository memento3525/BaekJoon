#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, c;
const int INF = 1e9;
int jewel[14];
int dp[11][21][1 << 14]; // 가방인덱스, 현재가방의 용량, 보석담았는지 여부

int Go(int bag, int bagCapacity, int mask)
{
    if (bag == m)
        return 0;

    int& ret = dp[bag][bagCapacity][mask];
    if (ret != -INF) return ret;

    // 다음 가방으로 넘기는 경우
    ret = max(ret, Go(bag + 1, c, mask));

    // i번째를 bag인덱스 가방에 담는 경우
    for (int i = 0; i < n; ++i)
    {
        bool alreadyPut = (1 << i) & mask;
        if (alreadyPut) continue;

        bool canPut = (bagCapacity >= jewel[i]);
        if (!canPut) continue;

        ret = max(ret, Go(bag, bagCapacity - jewel[i], mask | (1 << i)) + 1);
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0][0], &dp[0][0][0] + 11 * 21 * (1 << 14), -INF);

    cin >> n >> m >> c;

    for (int i = 0; i < n; ++i)
        cin >> jewel[i];

    cout << Go(0, c, 0);
}