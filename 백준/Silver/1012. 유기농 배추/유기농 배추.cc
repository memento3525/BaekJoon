#include <iostream>
#include <vector>
using namespace std;

int t, width, height, k;
vector<vector<int>> map;
vector<vector<bool>> visited;

int dirY[4] = { 1, 0, -1,  0 };
int dirX[4] = { 0, 1,  0, -1 };

void DFS(int y, int x)
{
    vector<pair<int, int>> open;
    open.push_back({ y, x });

    while (open.size())
    {
        pair<int, int> back = open.back();
        open.pop_back();

        for (int i = 0; i < 4; ++i)
        {
            int nextY = back.first + dirY[i];
            int nextX = back.second + dirX[i];

            if (nextY < 0 || nextY >= height) continue;
            if (nextX < 0 || nextX >= width) continue;

            if (map[nextY][nextX] == 0) continue;
            if (visited[nextY][nextX]) continue;

            visited[nextY][nextX] = true;
            open.push_back({ nextY, nextX });
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> width >> height >> k;

        map.clear();
        map.resize(height);
        visited.clear();
        visited.resize(height);

        for (int y = 0; y < height; ++y)
        {
            map[y] = vector<int>(width);
            visited[y] = vector<bool>(width);
        }

        for (int l = 0; l < k; ++l)
        {
            int y, x;
            cin >> x >> y;

            map[y][x] = 1;
        }

        int resultCount = 0;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (map[y][x] == 1 && !visited[y][x])
                {
                    DFS(y, x);
                    ++resultCount;
                }
            }
        }

        cout << resultCount << '\n';
    }
}