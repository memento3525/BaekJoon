#include <iostream>
using namespace std;

int n;
string prevName, name;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> prevName >> name;
    n -= 2;

    bool isIncrease = prevName < name;
    prevName = name;

    while (n--)
    {
        cin >> name;
        if ((isIncrease && prevName > name) || (!isIncrease && prevName < name))
        {
            cout << "NEITHER";
            return 0;
        }

        prevName = name;
    }
    
    cout << (isIncrease ? "INCREASING" : "DECREASING");
}