#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, a, B, b, P;

    cin >> A >> a >> B >> b >> P;

    if (A > P || B > P)
    {
        cout << "No";
        return 0;
    }

    if (A + B <= P)
    {
        cout << "Yes";
        return 0;
    }

    if (A <= b || B <= a)
    {
        cout << "Yes";
        return 0;
    }

    cout << "No";
}