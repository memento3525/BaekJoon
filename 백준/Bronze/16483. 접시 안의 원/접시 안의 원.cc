#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    double t;
    cin >> t;

    int ret = (int)((t * t / 4) + 0.5);
    cout << ret;
}