#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    double cur;
    cin >> cur; // 최초값

    double max = cur;

    double temp;
    for (int i = 1; i < n; ++i)
    {
        cin >> temp;

        if (cur > 1.0f)
            cur *= temp;
        else
            cur = temp;

        if (cur > max)
            max = cur;
    }

    cout << fixed << setprecision(3) << max;
}