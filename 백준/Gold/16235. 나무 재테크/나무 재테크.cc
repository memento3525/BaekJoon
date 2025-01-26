#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MN = 10;

int n, m, k;
int map[MN][MN];
int newTreeMap[MN][MN];
int manure[MN][MN]; // 거름
vector<int> trees[MN][MN];

int dy[8] = { -1,-1, 0, 1, 1, 1, 0,-1 };
int dx[8] = { 0, 1, 1, 1, 0,-1,-1,-1 };

void SpringSummer()
{
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            vector<int> tempTrees;
            int deadManure = 0;

            sort(trees[y][x].begin(), trees[y][x].end());

            for (int year : trees[y][x])
            {
                if (map[y][x] >= year)
                {
                    map[y][x] -= year;
                    tempTrees.push_back(year + 1);
                }
                else
                {
                    deadManure += year / 2;
                }
            }

            map[y][x] += deadManure;
            swap(trees[y][x], tempTrees);
        }
    }
}

void Fall()
{
    fill(&newTreeMap[0][0], &newTreeMap[0][0] + MN * MN, 0);

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            vector<int> tempTrees;
            for (int year : trees[y][x])
            {
                tempTrees.push_back(year);

                if (year % 5 == 0)
                {
                    for (int di = 0; di < 8; ++di)
                    {
                        int ny = y + dy[di];
                        int nx = x + dx[di];

                        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

                        newTreeMap[ny][nx] += 1;
                    }
                }
            }

            swap(trees[y][x], tempTrees);
        }
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            while (newTreeMap[y][x] > 0)
            {
                newTreeMap[y][x]--;
                trees[y][x].push_back(1);
            }
        }
    }
}

void Winter()
{
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            map[y][x] += manure[y][x];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    fill(&map[0][0], &map[0][0] + MN * MN, 5);

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            cin >> manure[y][x];
    }

    for (int i = 0; i < m; ++i)
    {
        int y, x, year;
        cin >> y >> x >> year;
        --y; --x;
        trees[y][x].push_back(year);
    }

    while (k--)
    {
        SpringSummer();
        Fall();
        Winter();
    }

    int ret = 0;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
            ret += trees[y][x].size();
    }

    cout << ret;
}