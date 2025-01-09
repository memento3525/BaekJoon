#include <iostream>
#include <vector>
using namespace std;

int height, width, m;
int dy[4]{ -1, 1, 0, 0 };
int dx[4]{ 0, 0, 1,-1 };
vector<int> map[101][101];

struct Shark
{
public:
    int _idx, _y, _x, _s, _d, _z;
    bool _isDead = false;

    Shark() : _idx(0), _y(0), _x(0), _s(0), _d(0), _z(0) { }

    Shark(int i, int y, int x, int s, int d, int z) :
        _idx(i), _y(y), _x(x), _s(s), _d(d), _z(z) { }

    void ChangeDir()
    {
        _d = (_d & 1) ? (_d - 1) : (_d + 1);
    }
};


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> m;
    if (m == 0)
    {
        cout << "0";
        return 0;
    }

    vector<Shark> sharks(m);

    int r, c, s, d, z;
    for (int i = 0; i < m; ++i)
    {
        cin >> r >> c >> s >> d >> z;
        --r; --c; --d;

        // 컨테이너 크기의 2n - 2 만큼 제거가능
        if (d <= 1)
            s %= ((height * 2) - 2);
        else
            s %= ((width * 2) - 2);

        sharks[i] = Shark(i, r, c, s, d, z);
        map[r][c].push_back(i);
    }

    int personX = 0;
    int ret = 0;
    int remain = m;
    while (personX != width && remain != 0)
    {
        // 사람의 낚시
        for (int y = 0; y < height; ++y)
        {
            if (map[y][personX].size())
            {
                int si = map[y][personX][0];

                ret += sharks[si]._z;
                sharks[si]._isDead = true;

                --remain;
                break;
            }
        }

        // 맵 비우기
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
                map[y][x].clear();
        }

        // 상어의 이동
        for (auto& sh : sharks)
        {
            if (sh._isDead)
                continue;

            int spd = sh._s;
            int ny = sh._y;
            int nx = sh._x;

            if (sh._d <= 1)
            {
                while (spd > 0)
                {
                    ny += dy[sh._d];

                    if (ny < 0 || ny >= height)
                    {
                        sh.ChangeDir();
                        ny += dy[sh._d] * 2;
                    }
                    --spd;
                }
            }
            else
            {
                while (spd > 0)
                {
                    nx += dx[sh._d];

                    if (nx < 0 || nx >= width)
                    {
                        sh.ChangeDir();
                        nx += dx[sh._d] * 2;
                    }
                    --spd;
                }
            }

            // 상어의 잡아먹기
            if (map[ny][nx].size())
            {
                auto& origin = sharks[map[ny][nx][0]];
                if (origin._z > sh._z)
                {
                    // 원래 있던애가 더 쎔
                    sh._isDead = true;
                }
                else
                {
                    // 새로 들어온놈이 더 쎔
                    origin._isDead = true;
                    map[ny][nx][0] = sh._idx;
                    sh._y = ny;
                    sh._x = nx;
                }
                --remain;
            }
            else
            {
                map[ny][nx].push_back(sh._idx);
                sh._y = ny;
                sh._x = nx;
            }
        }

        ++personX;
    }

    cout << ret;
    return 0;
}