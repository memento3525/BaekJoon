#include <iostream>
#include <vector>
using namespace std;

int t, n, m, a, b;
vector<vector<int>> map;

bool IsTree()
{
    vector<int> visited(n + 1);
    vector<int> open;
    open.reserve(n + 1);
    open.push_back(1);
    visited[1] = 1;

    int visitCnt = 1;
    while (!open.empty())
    {
        int back = open.back();
        open.pop_back();

        for (int i = 1; i <= n; ++i)
        {
            if (map[back][i])
            {
                if (visited[i])
                    return false;

                // 연결 끊음
                map[back][i] = 0;
                map[i][back] = 0;

                visited[i] = 1;
                open.push_back(i);
                ++visitCnt;
            }
        }
    }

    return visitCnt == n;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;

        map.resize(n + 1);
        for (int y = 0; y <= n; ++y)
        {
            map[y].resize(n + 1);
            for (int x = 0; x <= n; ++x)
                map[y][x] = 0;
        }

        if (n - 1 == m)
        {
            bool isGraph = false;
            for (int y = 0; y < m; ++y)
            {
                cin >> a >> b;

                if (map[a][b] == 1)
                    isGraph = true;

                map[a][b] = 1;
                map[b][a] = 1;
            }

            cout << (!isGraph && IsTree() ? "tree" : "graph") << '\n';
        }
        else
        {
            for (int y = 0; y < m; ++y)
                cin >> a >> b;

            cout << "graph" << '\n';
        }
    }
}