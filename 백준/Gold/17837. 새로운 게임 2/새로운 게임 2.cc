#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int endGameStack = 4;

int n, k;
int map[14][14];
vector<int> a[14][14];

int dy[4]{ 0, 0,-1, 1 };
int dx[4]{ 1,-1, 0, 0 };

// 개별 말의 정보
int pY[10];
int pX[10];
int pDir[10];

bool PlayTurn()
{
    for (int i = 0; i < k; ++i)
    {
        int y = pY[i];
        int x = pX[i];
        int& dir = pDir[i];

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        int color = map[ny][nx];

        if (color == 2) // 파란색 or 넘어감
        {
            dir = (dir & 1) ? dir - 1 : dir + 1;
            ny = y + dy[dir];
            nx = x + dx[dir];
            color = map[ny][nx];
            if (color == 2)
                continue;
        }

        vector<int>& cur = a[y][x];
        vector<int>& next = a[ny][nx];
        auto it = find(cur.begin(), cur.end(), i);
        if (color == 0) // 흰색
        {
            // 위에꺼를 그대로 이동함
            auto copied_it = it;

            while (copied_it != cur.end())
            {
                next.push_back(*copied_it);
                pY[*copied_it] = ny;
                pX[*copied_it] = nx;
                ++copied_it;
            }
        }
        else if (color == 1) // 빨간색
        {
            // 반전 시켜서이동함.
            auto rit = cur.rbegin();
            const auto rpos = make_reverse_iterator(it);

            while (rit != rpos)
            {
                next.push_back(*rit);
                pY[*rit] = ny;
                pX[*rit] = nx;
                ++rit;
            }
        }

        if (next.size() >= endGameStack)
            return true;

        cur.erase(it, cur.end());
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&map[0][0], &map[0][0] + 14 * 14, 2);
    cin >> n >> k;

    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= n; ++x)
            cin >> map[y][x];
    }

    for (int i = 0; i < k; ++i)
    {
        int y, x, d;
        cin >> y >> x >> d;

        pY[i] = y;
        pX[i] = x;
        pDir[i] = d - 1;

        a[y][x].push_back(i);
    }

    int turn = 0;
    while (true)
    {
        ++turn;
        if (turn > 1000)
        {
            cout << -1;
            return 0;
        }

        if (PlayTurn())
            break;
    }

    cout << turn;
}