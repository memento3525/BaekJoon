#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(3);

    double a, b, c, aa, bb, cc;
    int index = 1;
    while (true)
    {
        cin >> a >> b >> c;

        if (a == 0.0 && b == 0.0 && c == 0.0)
            break;

        aa = a * a;
        bb = b * b;
        cc = c * c;

        cout << "Triangle #" << index++ << '\n';

        if (a == -1.0)
        {
            int aa = cc - bb;
            if (aa <= 0.0)
            {
                cout << "Impossible." << '\n';
            }
            else
            {
                cout << "a = " << sqrt(aa) << '\n';
            }
        }
        else if (b == -1.0)
        {
            int bb = cc - aa;
            if (bb <= 0.0)
            {
                cout << "Impossible." << '\n';
            }
            else
            {
                cout << "b = " << sqrt(bb) << '\n';
            }
        }
        else if (c == -1.0)
        {
            int cc = aa + bb;
            cout << "c = " << sqrt(cc) << '\n';
        }

        cout << '\n';
    }
}