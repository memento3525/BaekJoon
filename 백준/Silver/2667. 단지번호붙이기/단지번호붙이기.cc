#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> map;
int dy[4]{ 0,-1, 0, 1 };
int dx[4]{ -1, 0, 1, 0 };
vector<int> rets;

void DFS(int startY, int startX, int color)
{
    vector<pair<int, int>> v;
    v.push_back({ startY, startX });
    map[startY][startX] = color;

    int cnt = 1;
    while (v.size())
    {
        int y = v.back().first;
        int x = v.back().second;
        v.pop_back();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (map[ny][nx] != 1) continue;

            map[ny][nx] = color;
            v.push_back({ ny, nx });
            ++cnt;
        }
    }
    rets.push_back(cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    map.resize(n);

    string str;
    for (int y = 0; y < n; ++y)
    {
        map[y].resize(n);

        cin >> str;

        for (int x = 0; x < n; ++x)
            map[y][x] = str[x] - '0';
    }

    int color = 2;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (map[y][x] == 1)
                DFS(y, x, color++);
        }
    }

    sort(rets.begin(), rets.end());

    cout << rets.size() << '\n';

    for (int i : rets)
        cout << i << '\n';
}