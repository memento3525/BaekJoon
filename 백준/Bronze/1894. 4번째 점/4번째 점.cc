#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

pair<string, string> a[2], b[2];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string x, y;
    while (cin >> x)
    {
        cin >> y;
        a[0] = { x, y };

        cin >> x >> y;
        a[1] = { x, y };

        cin >> x >> y;
        b[0] = { x, y };

        cin >> x >> y;
        b[1] = { x, y };

        if (a[0] == b[1])
        {
            swap(b[0], b[1]);
        }
        else if (a[1] == b[0])
        {
            swap(a[0], a[1]);
        }
        else if (a[1] == b[1])
        {
            swap(a[0], a[1]);
            swap(b[0], b[1]);
        }

        double deltaX = stod(a[1].first) - stod(a[0].first);
        double deltaY = stod(a[1].second) - stod(a[0].second);

        double retX = stod(b[1].first) + deltaX;
        double retY = stod(b[1].second) + deltaY;

        cout << fixed << setprecision(3) << retX << " " << retY << "\n";
    }
}