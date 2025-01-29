#include <iostream>
#include <vector>
using namespace std;

const int MN = 100001;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x, y;
    int maxX = -MN, maxY = -MN, minX = MN, minY = MN;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;

        maxX = max(maxX, x);
        minX = min(minX, x);
        maxY = max(maxY, y);
        minY = min(minY, y);
    }

    cout << ((maxX - minX) * (maxY - minY));
}