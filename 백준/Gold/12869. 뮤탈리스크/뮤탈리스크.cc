#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct A {
    int a, b, c;
};

vector<vector<vector<int>>> visited;
queue<A> q;
vector<A> dir
{
    { 9, 3, 1 },
    { 9, 1, 3 },
    { 3, 1, 9 },
    { 3, 9, 1 },
    { 1, 9, 3 },
    { 1, 3, 9 }
};

void Solve(int a, int b, int c)
{
    visited[a][b][c] = 1;
    q.push({ a, b, c });

    while (!q.empty())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if (visited[0][0][0]) break;

        for (int i = 0; i < 6; ++i)
        {
            A d = dir[i];
            int na = max(a - d.a, 0);
            int nb = max(b - d.b, 0);
            int nc = max(c - d.c, 0);

            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;

            q.push({ na, nb, nc });
        }
    }

    cout << visited[0][0][0] - 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    cin >> n;

    vector<int> hp(3);
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        hp[i] = temp;
    }

    visited.resize(hp[0] + 1);
    for (int a = 0; a < hp[0] + 1; ++a)
    {
        visited[a].resize(hp[1] + 1);
        for (int b = 0; b < hp[1] + 1; ++b)
        {
            visited[a][b].resize(hp[2] + 1);
        }
    }
        
    Solve(hp[0], hp[1], hp[2]);
}