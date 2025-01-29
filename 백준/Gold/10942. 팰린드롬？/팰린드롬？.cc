#include <iostream>
#include <vector>
using namespace std;

int n, m, s, e;

int arr[2001];
int dp[2001][2001];

int Check(int a, int b)
{
    if (a == b) return 1;
    if ((a + 1 == b) && arr[a] == arr[b]) return 1;
    if (arr[a] != arr[b]) return 0;

    int& ret = dp[a][b];
    if (ret != -1) return ret;

    ret = Check(a + 1, b - 1);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0], &dp[0][0] + 2001 * 2001, -1);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> s >> e;
        cout << Check(s, e) << '\n';
    }
}