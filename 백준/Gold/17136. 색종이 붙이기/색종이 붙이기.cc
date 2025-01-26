#include <iostream>
#include <vector>
using namespace std;

const int N = 10;
const int MAX_PAPER_N = 5;
int map[N][N];
int paper[6]{ 0, 5, 5, 5, 5, 5 };
int ret = INT32_MAX;

bool Check(int startY, int startX, int size)
{
    if (startY + size > N || startX + size > N) return false;

    for (int y = startY; y < startY + size; ++y)
    {
        for (int x = startX; x < startX + size; ++x)
        {
            if (map[y][x] == 0)
                return false;
        }
    }

    return true;
}

void DFS(int y, int x, int cnt)
{
    if (cnt > ret)
        return;

    if (x == N)
    {
        DFS(y + 1, 0, cnt);
        return;
    }
    if (y == N)
    {
        ret = min(ret, cnt);
        return;
    }
    if (map[y][x] == 0) // 구멍이 아니라서 다음으로 넘김
    {
        DFS(y, x + 1, cnt);
        return;
    }

    bool passed = 0;
    for (int size = 5; size > 0; --size)
    {
        if (paper[size] == 0) continue;

        if (passed || Check(y, x, size))
        {
            passed = true; // 더 높은 사이즈가 통과했다면 하위도 통과가능
            --paper[size];

            for (int yi = y; yi < y + size; ++yi)
            {
                for (int xi = x; xi < x + size; ++xi)
                    map[yi][xi] = 0;
            }

            DFS(y, x + size, cnt + 1);

            for (int yi = y; yi < y + size; ++yi)
            {
                for (int xi = x; xi < x + size; ++xi)
                    map[yi][xi] = 1;
            }

            ++paper[size];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
            cin >> map[y][x];
    }

    DFS(0, 0, 0);

    cout << (ret == INT32_MAX ? -1 : ret);
}