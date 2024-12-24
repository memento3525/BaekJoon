#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0, 1, 0,-1 };
int dx[4] = { 1, 0,-1, 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int height, width;
    cin >> height >> width;

    char c;

    vector<vector<char>> map;
    vector<vector<bool>> jvisited;
    queue<pair<int, int>> fireOpen_1, fireOpen_2;
    queue<pair<int, int>> jOpen_1, jOpen_2;

    queue<pair<int, int>>* fO = &fireOpen_1;
    queue<pair<int, int>>* fN = &fireOpen_2;
    queue<pair<int, int>>* jO = &jOpen_1;
    queue<pair<int, int>>* jN = &jOpen_2;

    map.resize(height);
    jvisited.resize(height);
    for (int y = 0; y < height; ++y)
    {
        map[y].resize(width);
        jvisited[y].resize(width);
        for (int x = 0; x < width; ++x)
        {
            cin >> c;
            map[y][x] = c;

            if (c == 'J')
            {
                jO->push({ y, x });
            }
            else if (c == 'F')
            {
                fO->push({y, x});
            }
        }
    }
    
    int time = 0;
    while (true)
    {
        ++time;

        // 불 이동
        {
            while (!fO->empty())
            {
                const auto& top = fO->front();
                int y = top.first;
                int x = top.second;
                fO->pop();

                for (int i = 0; i < 4; ++i)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (ny < 0 || ny >= height) continue;
                    if (nx < 0 || nx >= width) continue;
                    if (map[ny][nx] != '.') continue;

                    map[ny][nx] = 'F';
                    fN->push({ ny, nx });
                }
            }
        }

        // 지훈 이동
        {
            if (jO->empty())
            {
                time = -1;
                cout << "IMPOSSIBLE";
                return 0;
            }

            while (!jO->empty())
            {
                const auto& top = jO->front();
                int y = top.first;
                int x = top.second;
                jO->pop();

                if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
                {
                    cout << time;
                    return 0;
                }

                for (int i = 0; i < 4; ++i)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (ny < 0 || ny >= height) continue;
                    if (nx < 0 || nx >= width) continue;
                    if (map[ny][nx] != '.') continue;
                    if (jvisited[ny][nx]) continue;

                    jvisited[ny][nx] = true;
                    jN->push({ ny, nx });
                }
            }
        }

        if (time & 1)
        {
            fO = &fireOpen_2;
            fN = &fireOpen_1;
            jO = &jOpen_2;
            jN = &jOpen_1;
        }
        else
        {
            fO = &fireOpen_1;
            fN = &fireOpen_2;
            jO = &jOpen_1;
            jN = &jOpen_2;
        }
    }
}