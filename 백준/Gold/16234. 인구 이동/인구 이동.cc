#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> map;    
int n, l, r, temp;

int dy[4] = { 0, 1, 0,-1 };
int dx[4] = { 1, 0,-1, 0 };

vector<vector<bool>> visited;
vector<pair<int, int>> group;
int groupSum;

void DFS(int y, int x)
{
    visited[y][x] = true;

    groupSum += map[y][x];
    group.push_back({ y, x });

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx]) continue;

        int diff = abs(map[y][x] - map[ny][nx]);
        if (diff < l || r < diff) continue;

        DFS(ny, nx);
    }
}

bool SolveDay()
{
    bool anyDivide = false;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            visited[y][x] = false;
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (visited[y][x]) continue;

            groupSum = 0;
            group.clear();

            DFS(y, x);

            if (group.size() > 1)
            {
                anyDivide = true;
                int divided = floor(groupSum / group.size());
                for (const auto& g : group)
                    map[g.first][g.second] = divided;
            }
        }
    }

    return anyDivide;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;

    map.resize(n);
    visited.resize(n);
    for (int y = 0; y < n; ++y)
    {
        map[y].resize(n);
        visited[y].resize(n);
        for (int x = 0; x < n; ++x)
        {
            cin >> temp;
            map[y][x] = temp;
        }
    }

    int day = 0;
    while (SolveDay())
        ++day;

    cout << day;
}