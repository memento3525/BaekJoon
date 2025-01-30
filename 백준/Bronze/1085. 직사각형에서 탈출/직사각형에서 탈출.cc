#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    vector<int> v(4);
    v[0] = x;
    v[1] = w - x;
    v[2] = y;
    v[3] = h - y;

    sort(v.begin(), v.end());
    cout << v[0];
}