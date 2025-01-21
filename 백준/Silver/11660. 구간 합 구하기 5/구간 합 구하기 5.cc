#include <iostream>
#include <vector>
using namespace std;

int n, t;
vector<vector<int>> map;
vector<vector<int>> dp;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;

    int np1 = n + 1;

    map.assign(np1, vector<int>(np1));
    dp.assign(np1, vector<int>(np1));

    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= n; ++x)
        {
            cin >> map[y][x];
            dp[y][x] = map[y][x] + dp[y - 1][x] + dp[y][x - 1] - dp[y - 1][x - 1];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < t; ++i)
    {
        cin >> y1 >> x1 >> y2 >> x2;

        int sum = dp[y2][x2] 
            - dp[y2][x1 - 1] 
            - dp[y1 - 1][x2] 
            + dp[y1 - 1][x1 - 1];

        cout << sum << '\n';
    }
}