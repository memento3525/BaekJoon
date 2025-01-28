#include <iostream>
#include <iomanip>
using namespace std;

const double pi = 3.141592;

int main(void)
{
    int w, h;
    cin >> w >> h;

    double ret = 2 * (w + h * pi);
    cout << fixed << setprecision(7) << ret;
}