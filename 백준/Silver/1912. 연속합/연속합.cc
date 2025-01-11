#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cur;
    int max = -1001;
    int curSum = 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> cur;

        curSum += cur;

        if (curSum > max)
            max = curSum;

        if (curSum < 0)
            curSum = 0;
    }

    cout << max;
    return 0;
}