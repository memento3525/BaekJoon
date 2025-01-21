#include <iostream>
#include <vector>
using namespace std;

int n, t;
vector<vector<int>> map;
vector<vector<int>> xSum;
vector<vector<int>> ySum;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;

    int np1 = n + 1;

    map.assign(np1, vector<int>(np1));
    xSum.assign(np1, vector<int>(np1));
    ySum.assign(np1, vector<int>(np1));

    for (int y = 1; y <= n; ++y)
    {
        int sum = 0;
        for (int x = 1; x <= n; ++x)
        {
            cin >> map[y][x];
            sum += map[y][x];
            xSum[y][x] = sum;
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        int sum = 0;
        for (int y = 1; y <= n; ++y)
        {
            sum += map[y][x];
            ySum[y][x] = sum;
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < t; ++i)
    {
        cin >> y1 >> x1 >> y2 >> x2;

        int h = y2 - y1;
        int w = x2 - x1;

        int sum = 0;
        if (h > w)
        {
            // y Sum
            for (int x = x1; x <= x2; ++x)
            {
                sum += ySum[y2][x] - ySum[y1 - 1][x];
            }
        }
        else
        {
            // x Sum
            for (int y = y1; y <= y2; ++y)
                sum += xSum[y][x2] - xSum[y][x1 - 1];
        }

        cout << sum << '\n';
    }
}