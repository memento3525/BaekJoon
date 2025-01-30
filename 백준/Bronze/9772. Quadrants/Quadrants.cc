#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    float x, y;

    bool hasInput = true;
    while (hasInput)
    {
        cin >> x >> y;

        if (x == 0.0 && y == 0.0)
        {
            cout << "AXIS" << '\n';
            hasInput = false;
            continue;
        }

        if (x == 0.0 || y == 0.0)
        {
            cout << "AXIS" << '\n';
            continue;
        }

        if (x > 0.0)
        {
            if (y > 0.0)
            {
                cout << "Q1" << '\n';
            }
            else if (y < 0.0)
            {
                cout << "Q4" << '\n';
            }
        }
        else if (x < 0.0)
        {
            if (y > 0.0)
            {
                cout << "Q2" << '\n';
            }
            else if (y < 0.0)
            {
                cout << "Q3" << '\n';
            }
        }
    }
}