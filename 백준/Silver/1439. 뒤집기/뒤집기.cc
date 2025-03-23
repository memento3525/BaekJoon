#include <iostream>
#include <vector>
using namespace std;

string s;

int main(void)
{
    cin >> s;

    bool isZero = s[0] == '0';
    int cnt = 0;

    for (const char& c : s)
    {
        if ((c == '0' && !isZero) || (c == '1' && isZero))
        {
            isZero = !isZero;
            cnt++;
        }
    }

    if (cnt == 0)
        cout << 0;
    else
        cout << ((cnt - 1) / 2) + 1;
}