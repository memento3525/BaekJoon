#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int height, width;
int choco_y, choco_x, start_y, start_x;
vector<vector<char>> map;
vector<vector<int>> visited;
int dy[4] = { 0, 1, 0,-1 };
int dx[4] = { 1, 0,-1, 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;
    cin >> start_y >> start_x >> choco_y >> choco_x;
    --start_y;
    --start_x;
    --choco_y;
    --choco_x;

    char temp;
    map.resize(height);
    visited.resize(height);
    for (int y = 0; y < height; ++y)
    {
        map[y].resize(width);
        visited[y].resize(width);
        for (int x = 0; x < width; ++x)
        {
            cin >> temp;
            map[y][x] = temp;
        }
    }
    
    int turn = 0;
    while (true)
    {
        ++turn;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
                visited[y][x] = 0;
        }

        visited[start_y][start_x] = 1;
        queue<pair<int, int>> q;
        q.push({ start_y, start_x });

        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= height) continue;
                if (nx < 0 || nx >= width) continue;
                if (visited[ny][nx]) continue;

                if (choco_y == ny && choco_x == nx)
                {
                    cout << turn;
                    return 0;
                }

                visited[ny][nx] = visited[y][x] + 1;

                if (map[ny][nx] == '0')
                    q.push({ ny,nx });
                
                map[ny][nx] = '0';
            }
        }
    }
}