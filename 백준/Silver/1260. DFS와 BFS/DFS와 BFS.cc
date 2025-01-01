#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;

    vector<vector<int>> adj(n + 1);
    vector<int> visited(n + 1);

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());

    // DFS
    vector<int> s;
    s.push_back(v);

    while (s.size())
    {
        int cur = s.back();
        s.pop_back();

        if (visited[cur]) continue;
        visited[cur] = 1;

        cout << cur << ' ';

        for (int i = adj[cur].size() - 1; i >= 0; --i)
        {
            int next = adj[cur][i];
            s.push_back(next);
        }
    }
    cout << '\n';

    // BFS
    fill(visited.begin(), visited.end(), 0);
    queue<int> q;
    q.push(v);

    while (q.size())
    {
        int cur = q.front();
        q.pop();

        if (visited[cur]) continue;
        visited[cur] = 1;

        cout << cur << ' ';

        for (int i = 0; i < adj[cur].size(); ++i)
        {
            int next = adj[cur][i];
            q.push(next);
        }
    }
}