#include <iostream>
using namespace std;

int n;
int a[1001][1001];
int myY, myX, enemyY, enemyX;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            cin >> a[y][x];

            if (a[y][x] == 2)
            {
                myY = y;
                myX = x;
            }
            else if (a[y][x] == 5)
            {
                enemyY = y;
                enemyX = x;
            }
        }
    }

    int dy = abs(myY - enemyY);
    int dx = abs(myX - enemyX);
    if (dy * dy + dx * dx < 25)
    {
        cout << "0";
        return 0;
    }

    int minX = min(myX, enemyX);
    int maxX = max(myX, enemyX);
    int minY = min(myY, enemyY);
    int maxY = max(myY, enemyY);

    int gaurd = 0;
    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            if (a[y][x] == 1)
                ++gaurd;
        }
    }

    cout << ((gaurd >= 3) ? "1" : "0") << '\n';
}