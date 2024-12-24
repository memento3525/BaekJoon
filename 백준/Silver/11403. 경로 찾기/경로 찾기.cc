#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
vector<bool> visited;
vector<int> open;

int Solve(int a, int b)
{
    if (map[a][b] == 1) 
        return 1;

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    open.clear();
    open.emplace_back(a);

    while (!open.empty())
    {
        int top = open.back();
        open.pop_back();

        for (int i = 0; i < n; ++i)
        {
            if (visited[i]) continue;
            if (map[top][i] == 0) continue;
            if (i == b)
                return 1;

            visited[i] = true;
            open.emplace_back(i);
        }
    }
    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    open.reserve(n);
    visited.resize(n);
    map.resize(n);
    for (int y = 0; y < n; ++y)
    {
        map[y].resize(n);
        for (int x = 0; x < n; ++x)
            cin >> map[y][x];
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            cout << Solve(y, x) << ' ';

        cout << '\n';
    }
}