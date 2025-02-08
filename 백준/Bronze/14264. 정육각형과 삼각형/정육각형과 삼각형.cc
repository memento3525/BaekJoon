#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(void)
{
    double l;
    cin >> l;

    cout << fixed << setprecision(9) << (l * l) / 4 * sqrt(3);
}