#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, v;
    cin >> a >> b >> v;

    int day = 0;
    int remain = v;
    int interval = a - b;

    while (remain >= a)
    {
        int div = remain / a;

        if (div == 1 && remain % a == 0) // 마지막 스탭
        {
            ++day;
            remain = 0;
            break;
        }
        else if (div > 0)
        {
            day += div;
            remain -= div * interval;
        }
        else
        {
            break;
        }
    }

    if (remain > 0)
        ++day;

    cout << day;
}