#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, j;
    cin >> n >> m >> j;

    int apple;
    int left = 1;
    int result = 0;
    for (int i = 0; i < j; ++i)
    {
        cin >> apple;

        int right = left + m - 1;

        if (left <= apple && apple <= right) continue;

        int dist = 0;
        if (apple < left)
        {
            dist = left - apple;
            left -= dist;
        }
        else // (right < apple)
        {
            dist = apple - right;
            left += dist;
        }
        result += dist;
    }

    cout << result;
}