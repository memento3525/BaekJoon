#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int minX = 99, minY = 99, maxX = -99, maxY = -99;
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 < minX) minX = x1;
        if (x1 > maxX) maxX = x1;
        
        if (y1 < minY) minY = y1;
        if (y1 > maxY) maxY = y1;

        if (x2 > maxX) maxX = x2;
        if (x2 < minX) minX = x2;

        if (y2 > maxY) maxY = y2;
        if (y2 < minY) minY = y2;

        int len = abs(maxX - minX) * 2 + abs(maxY - minY) * 2;
        cout << len << '\n';
    }
}