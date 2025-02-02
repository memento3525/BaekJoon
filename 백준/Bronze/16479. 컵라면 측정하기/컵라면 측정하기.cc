#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double k, d1, d2;
    cin >> k >> d1 >> d2;

    double bottom = (d1 - d2) / 2;
    double ret = k * k - bottom * bottom;

    cout << fixed << setprecision(6) << ret;
}