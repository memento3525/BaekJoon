#include <iostream>
#include <vector>
using namespace std;
int dy[4]{ 0,-1, 0, 1 };
int dx[4]{ 1, 0,-1, 0 };

int n, m;
vector<vector<int>> map;
vector<int> teams;

int ret = INT32_MAX;

void Combi(int start, int cnt)
{
    if (cnt == m)
    {
        int diff = 0;
        for (int a = 0; a < teams.size(); ++a)
        {
            for (int b = 0; b < teams.size(); ++b)
            {
                if (a == b) continue;
                if (teams[a] != teams[b]) continue;

                if (teams[a] == 0)
                    diff += map[a][b];
                else
                    diff -= map[a][b];
            }
        }

        if (diff < 0)
            diff = -diff;

        if (diff < ret)
            ret = diff;

        return;
    }

    for (int i = start + 1; i < n; ++i)
    {
        teams[i] = 1;
        Combi(i, cnt + 1);
        teams[i] = 0;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    m = n / 2;

    teams.resize(n);
    map.resize(n);
    for (int y = 0; y < n; ++y)
    {
        map[y].resize(n);
        for (int x = 0; x < n; ++x)
            cin >> map[y][x];
    }

    Combi(-1, 0);

    cout << ret;
}