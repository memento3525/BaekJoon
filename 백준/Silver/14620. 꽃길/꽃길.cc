#include <iostream>
#include <vector>

using namespace std;

int dy[5] = { 0, 0, 1, 0,-1 };
int dx[5] = { 0, 1, 0,-1, 0 };
int n;
int ret = INT32_MAX;
vector<vector<int>> map;
vector<vector<int>> visited;

int Plant(int y, int x)
{
    int price = 0;

    for (int i = 0; i < 5; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        visited[ny][nx] = 1;
        price += map[ny][nx];
    }

    return price;
}

bool CanPlant(int y, int x)
{
    for (int i = 0; i < 5; ++i)
    {
        if (visited[y + dy[i]][x + dx[i]])
            return false;
    }
    return true;
}

void Go(int cnt, int sum)
{
    if (cnt == 3)
    {
        if (sum < ret)
            ret = sum;

        return;
    }

    for (int y = 1; y < n - 1; ++y)
    {
        for (int x = 1; x < n - 1; ++x)
        {
            if (!CanPlant(y, x)) continue;

            int newPrice = Plant(y, x);
            Go(cnt + 1, sum + newPrice);

            for (int i = 0; i < 5; ++i)
                visited[y + dy[i]][x + dx[i]] = 0;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    map.resize(n);
    visited.resize(n);
    for (int y = 0; y < n; ++y)
    {
        map[y].resize(n);
        visited[y].resize(n);
        for (int x = 0; x < n; ++x)
            cin >> map[y][x];
    }

    Go(0, 0);

    cout << ret;
}