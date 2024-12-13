#include <iostream>
using namespace std;

int main(void)
{
    int a, b, v;
    cin >> a >> b >> v;

    int target = v - a;
    int interval = a - b;

    int day = target / interval + 1;

    if (target % interval != 0)
        ++day;

    cout << day;
}