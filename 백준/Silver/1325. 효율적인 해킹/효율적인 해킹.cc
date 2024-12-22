#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;

int DFS(int n)
{
    visited[n] = true;
    if (v[n].empty())
        return 1;

    int count = 1;
    for (const int& i : v[n])
    {
        if (visited[i]) continue;

        count += DFS(i);
    }
    return count;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;
    v.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        v[b].emplace_back(a);
    }

    int max = 0;
    vector<int> result;
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 0; k < visited.size(); ++k)
            visited[k] = false;

        int count = DFS(i);
        if (count > max)
        {
            max = count;
            result.clear();
            result.push_back(i);
        }
        else if (count == max)
        {
            result.push_back(i);
        }
    }

    sort(result.begin(), result.end());

    for (const int& i : result)
        cout << i << ' ';
}