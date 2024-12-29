#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> people;
vector<vector<int>> map;
vector<int> visited;
vector<int> colors;

int n;
int colorSum[3]{};
int ret = INT32_MAX;

int DFS(int index, int color)
{
    colorSum[color] += people[index];
    int cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        if (visited[i]) continue;

        if (colors[i] == color && map[index][i])
        {
            visited[i] = 1;
            cnt += DFS(i, color);
        }
    }

    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    people.resize(n);
    map.resize(n);
    colors.resize(n);
    visited.resize(n);

    for (int y = 0; y < n; ++y)
    {
        cin >> people[y];
        map[y].resize(n);
    }

    int k, width;
    for (int y = 0; y < n; ++y)
    {
        cin >> width;

        for (int x = 0; x < width; ++x)
        {
            cin >> k;

            map[y][k - 1] = 1;
            map[k - 1][y] = 1;
        }
    }

    for (int i = 1; i < (1 << n) - 1; ++i)
    {
        colorSum[1] = 0;
        colorSum[2] = 0;

        int index1 = -1;
        int index2 = -1;
        for (int k = 0; k < n; ++k)
        {
            if (i & (1 << k))
            {
                colors[k] = 1;
                index1 = k;
            }
            else
            {
                colors[k] = 2;
                index2 = k;
            }
        }

        for (int y = 0; y < n; ++y)
            visited[y] = 0;
        visited[index1] = 1;
        int n1 = DFS(index1, 1);

        for (int y = 0; y < n; ++y)
            visited[y] = 0;
        visited[index2] = 1;
        int n2 = DFS(index2, 2);

        if (n1 + n2 == n)
        {
            int cur = abs(colorSum[1] - colorSum[2]);
            if (cur < ret)
                ret = cur;
        }
    }

    cout << (ret == INT32_MAX ? -1 : ret);
}