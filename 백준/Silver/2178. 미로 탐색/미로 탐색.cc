#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string temp;
    vector<vector<int>> visited(n);
    queue<pair<int, int>> open;

    for (int y = 0; y < n; ++y)
    {
        cin >> temp;

        visited[y] = vector<int>(m);
        for (int x = 0; x < m; ++x)
        {
            if (temp[x] == '0')
                visited[y][x] = -1;
        }
    }

    int dirY[4] = { 0, 1,  0, -1 };
    int dirX[4] = { 1, 0, -1,  0 };

    visited[0][0] = 1;
    open.push(make_pair(0, 0));

    int y = 0, x = 0;
    while (open.size() != 0)
    {
        pair<int, int> current = open.front();
        open.pop();

        y = current.first;
        x = current.second;

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + dirY[i];
            int dx = x + dirX[i];

            if (dy < 0 || dy >= n) continue;
            if (dx < 0 || dx >= m) continue;
            if (visited[dy][dx] != 0) continue;

            visited[dy][dx] = visited[y][x] + 1;

            if (dy == n - 1 && dx == m - 1)
            {
                cout << visited[dy][dx];
                return 0;
            }

            open.push(make_pair(dy, dx));
        }
    }
}