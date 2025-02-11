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

    int x, y, r;
    cin >> x >> y >> r;

    int min = x - r;
    int max = x + r;

    int temp;
    int rets[2] = { 0, 0 };
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;

        if (temp == min || temp == max)
            ++rets[1];
        else if(min < temp && temp < max)
            ++rets[0];
    }

    cout << rets[0] << ' ' << rets[1];
}