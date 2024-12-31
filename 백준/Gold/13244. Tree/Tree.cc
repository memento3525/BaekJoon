#include <iostream>
#include <vector>
using namespace std;

int t, n, m, a, b;
int connected[1001][1001];

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
            if (connected[back][i])
            {
                if (visited[i])
                    return false;

                // 연결 끊음
                connected[back][i] = 0;
                connected[i][back] = 0;

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
        fill(&connected[0][0], &connected[0][0] + 1001 * 1001, 0);

        cin >> n >> m;

        bool isGraph = false;
        for (int y = 0; y < m; ++y)
        {
            cin >> a >> b;

            if (connected[a][b] == 1)
                isGraph = true;

            connected[a][b] = 1;
            connected[b][a] = 1;
        }

        cout << (!isGraph && IsTree() ? "tree" : "graph") << '\n';
    }
}