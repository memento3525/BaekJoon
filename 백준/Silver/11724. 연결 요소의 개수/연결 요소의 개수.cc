#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visited;
vector<int> s;

void DFS(int n)
{
    s.clear();
    s.push_back(n);
    visited[n] = 1;

    while (s.size())
    {
        int cur = s.back();
        s.pop_back();

        for (int i = 0; i < adj[cur].size(); ++i)
        {
            int next = adj[cur][i];

            if (visited[next]) continue;
            
            s.push_back(next);
            visited[next] = 1;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1);

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ret = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            ++ret;
            DFS(i);
        }
    }

    cout << ret;
}