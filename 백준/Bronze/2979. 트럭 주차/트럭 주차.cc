#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    b *= 2;
    c *= 3;

    int time[101]{};
    
    int start, end;
    for (int i = 0; i < 3; ++i)
    {
        cin >> start >> end;

        for (int i = start; i < end; ++i)
        {
            ++time[i];
        }
    }

    int sum = 0;
    for (int i : time)
    {
        if (i == 0) continue;
        if (i == 1) sum += a;
        if (i == 2) sum += b;
        if (i == 3) sum += c;
    }

    cout << sum;
}