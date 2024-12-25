#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int height, width;

int spawnY;
int spawnX;
vector<vector<char>> map;
int dy[4] = { 0, 1, 0,-1 };
int dx[4] = { 1, 0,-1, 0 };

queue<pair<int, int>> swanQ, swan_nextQ, waterQ, water_nextQ;
vector<vector<bool>> visited_swan, visited_water;

void Water_Melt()
{
    while (!waterQ.empty())
    {
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= height) continue;
            if (nx < 0 || nx >= width) continue;
            if (visited_water[ny][nx]) continue;

            if (map[ny][nx] == 'X')
            {
                visited_water[ny][nx] = true;
                water_nextQ.push({ ny, nx });
                map[ny][nx] = '.';
            }
        }
    }
}

bool Move_Swan()
{
    while (!swanQ.empty())
    {
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= height) continue;
            if (nx < 0 || nx >= width) continue;
            if (visited_swan[ny][nx]) continue;

            if (map[ny][nx] == 'L')
                return true;

            visited_swan[ny][nx] = true;
            if (map[ny][nx] == '.')
            {
                swanQ.push({ ny, nx });
            }
            else if (map[ny][nx] == 'X')
            {
                swan_nextQ.push({ ny, nx });
            }
        }
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    char temp;
    map.resize(height);
    visited_swan.resize(height);
    visited_water.resize(height);
    for (int y = 0; y < height; ++y)
    {
        map[y].resize(width);
        visited_swan[y].resize(width);
        visited_water[y].resize(width);
        for (int x = 0; x < width; ++x)
        {
            cin >> temp;
            map[y][x] = temp;

            if (temp == 'L')
            {
                spawnY = y;
                spawnX = x;
            }

            if (temp == '.' || temp == 'L')
            {
                waterQ.push({ y, x });
                visited_water[y][x] = true;
            }
        }
    }

    visited_swan[spawnY][spawnX] = true;
    swanQ.push({ spawnY, spawnX });

    int turn = 0;
    while (true)
    {
        if (Move_Swan())
            break;

        Water_Melt();

        waterQ = water_nextQ;
        queue<pair<int, int>> temp;
        swap(water_nextQ, temp);

        swanQ = swan_nextQ;
        queue<pair<int, int>> temp2;
        swap(swan_nextQ, temp2);

        ++turn;
    }

    cout << turn;
}