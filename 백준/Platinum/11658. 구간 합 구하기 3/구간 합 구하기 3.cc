#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1025;
int n, m;
int num[MAX_N][MAX_N];
int bit[MAX_N][MAX_N];

void Update(int y, int x, int value)
{
    while (y <= n)
    {
        int j = x;
        while (j <= n)
        {
            bit[y][j] += value;
            j += (j & -j);
        }

        y += (y & -y);
    }
}

int Sum(int y, int x)
{
    int ret = 0;
    while (y > 0)
    {
        int j = x;
        while (j > 0)
        {
            ret += bit[y][j];
            j -= (j & -j);
        }

        y -= (y & -y);
    }
    return ret;
}

int Query(int y1, int x1, int y2, int x2)
{
    int ret = 0;
    ret += Sum(y2, x2);
    ret += Sum(y1 - 1, x1 - 1);
    ret -= Sum(y1 - 1, x2);
    ret -= Sum(y2, x1 - 1);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= n; ++x)
        {
            cin >> num[y][x];
            Update(y, x, num[y][x]);
        }
    }

    int w;
    for (int i = 0; i < m; ++i)
    {
        cin >> w;
        
        if (w == 0) // (x, y)를 c로 바꾸는 연산
        {
            int y, x, c;
            cin >> y >> x >> c;

            int diff = c - num[y][x];
            num[y][x] = c;
            Update(y, x, diff);
        }
        else // (x1, y1) 부터 (x2, y2)의 합을 구해 출력
        {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;

            cout << Query(y1, x1, y2, x2) << '\n';
        }
    }
}