#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int dy[5] = { 0, 0, 1, 0,-1 };
int dx[5] = { 0, 1, 0,-1, 0 };
int n;
int ret = INT32_MAX;
vector<vector<int>> map;
vector<vector<int>> visited;
vector<pair<int, int>> flower;

bool CheckIntersection(const pair<int, int>& a, const pair<int, int>& b)
{
    if (abs(a.first - b.first) <= 1 && abs(a.second - b.second) <= 1) return true;
    if (a.first == b.first && abs(a.second - b.second) == 2) return true;
    if (a.second == b.second && abs(a.first - b.first) == 2) return true;

    return false;
}

bool CheckDeath()
{
    if (flower.size() >= 2)
    {
        if (CheckIntersection(flower[0], flower[1])) return true;

        if (flower.size() >= 3)
        {
            if (CheckIntersection(flower[0], flower[2])) return true;
            if (CheckIntersection(flower[1], flower[2])) return true;
        }
    }
    return false;
}

int CheckPrice()
{
    int sum = 0;
    for (const auto& f : flower)
    {
        sum += map[f.first][f.second];
        sum += map[f.first + 1][f.second];
        sum += map[f.first - 1][f.second];
        sum += map[f.first][f.second + 1];
        sum += map[f.first][f.second - 1];
    }
    return sum;
}

void Go()
{
    if (CheckDeath())
        return;

    if (flower.size() == 3)
    {
        int price = CheckPrice();
        if (price < ret)
            ret = price;

        return;
    }

    for (int y = 1; y < n - 1; ++y)
    {
        for (int x = 1; x < n - 1; ++x)
        {
            if (visited[y][x]) continue;

            for (int i = 0; i < 5; ++i)
                visited[y + dy[i]][x + dx[i]] = 1;

            flower.push_back({ y, x });
            Go();
            flower.pop_back();

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

    Go();

    cout << ret;
}