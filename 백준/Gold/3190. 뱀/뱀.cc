#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[4]{ 0, 1, 0,-1 };
int dx[4]{ 1, 0,-1, 0 };

vector<vector<int>> map;
queue<pair<int, char>> rot;

const int APPLE = 1;
const int BODY = 2;
int n, k, l;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    map.assign(n, vector<int>(n));

    for (int i = 0; i < k; ++i)
    {
        int y, x;
        cin >> y >> x;
        map[y - 1][x - 1] = APPLE;
    }

    cin >> l;
    for (int i = 0; i < l; ++i)
    {
        int t;
        char c;
        cin >> t >> c;
        rot.push({ t, c });
    }

    int ret = 0;
    int dir = 0;
    int y = 0;
    int x = 0;
    queue<pair<int, int>> snake;
    snake.push({ 0, 0 });
    map[0][0] = BODY;
    while (true)
    {
        ++ret;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
        if (map[ny][nx] == BODY) break;

        snake.push({ ny, nx });
        if (map[ny][nx] == APPLE)
        {
            map[ny][nx] = BODY;
        }
        else
        {
            map[ny][nx] = BODY;
            map[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }

        if (rot.size() && rot.front().first == ret)
        {
            if (rot.front().second == 'L') // 왼쪽
                dir = (dir + 3) % 4;
            else // 오른쪽
                dir = (dir + 1) % 4;

            rot.pop();
        }

        y = ny;
        x = nx;
    }

    cout << ret;
}