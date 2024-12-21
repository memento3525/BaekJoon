#include <iostream>
#include <vector>
using namespace std;

int height, width;
vector<vector<int>> map;
vector<pair<int, int>> virus;
vector<pair<int, int>> blank;
vector<vector<bool>> visited;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void DFS(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= height) continue;
        if (nx < 0 || nx >= width) continue;
        if (visited[ny][nx]) continue;
        if (map[ny][nx] == 1) continue;

        visited[ny][nx] = true;
        DFS(ny, nx);
    }
}

int Method()
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            visited[y][x] = false;
    }

    for (const auto& item : virus)
    {
        visited[item.first][item.second] = true;
        DFS(item.first, item.second);
    }

    int safe = 0;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (map[y][x] == 0 && !visited[y][x])
                ++safe;
        }
    }

    return safe;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    map.resize(height);
    visited.resize(height);

    int temp;
    for (int y = 0; y < height; ++y)
    {
        map[y] = vector<int>(width);
        visited[y] = vector<bool>(width);
        for (int x = 0; x < width; ++x)
        {
            cin >> temp;
            map[y][x] = temp;

            if (temp == 0) blank.push_back({ y, x });
            if (temp == 2) virus.push_back({ y, x });
        }
    }

    int result = 0;
    for (int i = 0; i < blank.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                map[blank[i].first][blank[i].second] = 1;
                map[blank[j].first][blank[j].second] = 1;
                map[blank[k].first][blank[k].second] = 1;
                result = max(result, Method());
                map[blank[i].first][blank[i].second] = 0;
                map[blank[j].first][blank[j].second] = 0;
                map[blank[k].first][blank[k].second] = 0;
            }
        }
    }

    cout << result;
}