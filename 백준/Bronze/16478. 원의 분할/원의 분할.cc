#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double ab, bc, cd;
    cin >> ab >> bc >> cd;

    double ad = ab * cd / bc;
    cout << fixed << setprecision(6) << ad;
}