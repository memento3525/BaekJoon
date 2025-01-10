#include <iostream>
#include <vector>
using namespace std;

int dy[4]{ 0,-1, 0, 1 };
int dx[4]{ 1, 0,-1, 0 };
int map[101][101];

int n, x, y, d, g;
vector<int> dragon[4][11];

void MakeDragon()
{
    for (int i = 0; i < 4; i++)
    {
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i + 1) % 4);

        // 2세대 ~ 10 세대
        for (int j = 2; j <= 10; ++j)
        {
            // 이전 세대의 크기
            int n = dragon[i][j - 1].size();

            // 역순의 + 1 모듈러
            for (int k = n - 1; k >= 0; --k)
            {
                dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
            }

            // 이전세대를 넣기
            for (int k = 0; k < n; ++k)
            {
                dragon[i][j].push_back(dragon[i][j - 1][k]);
            }
        }
    }
}

void Go(int x, int y, int d, int g)
{
    map[x][y] = 1;

    // 1 ~ g 세대까지의 커브를 겹침
    for (int i = 0; i <= g; ++i)
    {
        for (int dir : dragon[d][i])
        {
            x += dx[dir];
            y += dy[dir];
            map[x][y] = 1;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    MakeDragon();
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y >> d >> g;
        Go(x, y, d, g);
    }

    int ret = 0;
    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0; j < 101; ++j)
        {
            if (map[i][j] && map[i + 1][j] && 
                map[i][j + 1] && map[i + 1][j + 1])
                ++ret;
        }
    }
    cout << ret;
}