#include <iostream>
using namespace std;

int main(void)
{
    int r, w, l, i = 0;
    while (cin >> r)
    {
        ++i;
        if (r == 0) break;
        cin >> w >> l;

        cout << "Pizza " << i;
        if (4 * r * r < w * w + l * l)
            cout << " does not fit on the table.\n";
        else
            cout << " fits on the table.\n";
    }
}