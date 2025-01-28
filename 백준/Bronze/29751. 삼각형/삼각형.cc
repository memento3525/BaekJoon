#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int w, h;
    cin >> w >> h;

    float ret = w * h * 0.5;
    cout << fixed << setprecision(1) << ret;
}