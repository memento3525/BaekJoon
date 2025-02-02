#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int ret = 0;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];

        if(i == 0) continue;

        ret += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    }

    ret += abs(x[0] - x[n - 1]) + abs(y[0] - y[n - 1]);
    cout << ret;
}