#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(void)
{
    double r;
    cin >> r;

    cout << fixed << setprecision(6) << r * r * M_PI << '\n' << (r * r * 2.0);
}