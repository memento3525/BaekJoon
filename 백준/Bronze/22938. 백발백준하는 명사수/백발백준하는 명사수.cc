#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using ll = long long;

int main(void)
{
    ll x1, y1, r1;
    ll x2, y2, r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ll distX = abs(x2 - x1);
    ll distY = abs(y2 - y1);

    double dd = distX * distX + distY * distY;
    double rr = (r1 + r2) * (r1 + r2);

    if (dd < rr)
        cout << "YES";
    else
        cout << "NO";
}