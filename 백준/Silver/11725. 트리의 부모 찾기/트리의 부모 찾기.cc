#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> connect;
vector<int> visited;

void Go(int i)
{
    for (int node : connect[i])
    {
        if (visited[node] != 0) continue;

        visited[node] = i;
        Go(node);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    connect.assign(n + 1, vector<int>());

    int a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    visited.resize(n + 1);

    visited[0] = 1;
    Go(1);

    for (int i = 2; i <= n; ++i)
        cout << visited[i] << '\n';
}