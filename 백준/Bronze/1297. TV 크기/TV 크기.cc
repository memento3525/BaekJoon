#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    int d, h, w;
    cin >> d >> h >> w;

    double k = sqrt(d * d / (double)(h * h + w * w));
    int realH = k * h;
    int realW = k * w;

    cout << realH << ' ' << realW;
}