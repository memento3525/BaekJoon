#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ret;
vector<int> visited;

void Dfs(int depth)
{
    if (depth == m)
    {
        for (int i : ret)
            cout << i << ' ';

        cout << '\n';

        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i]) continue;
        
        visited[i] = 1;
        ret[depth] = i + 1;
        Dfs(depth + 1);
        visited[i] = 0;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    visited.resize(n);
    ret.resize(m);

    Dfs(0);
}