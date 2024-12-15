#include <iostream>
using namespace std;

bool IsValidNumber(int n)
{
    int sixCount = 0;
    while (n != 0)
    {
        if (n % 10 == 6)
        {
            ++sixCount;

            if (sixCount >= 3)
                return true;
        }
        else
        {
            sixCount = 0;
        }

        n /= 10;
    }

    return false;
}

int main(void)
{
    int n;
    cin >> n;

    int current = 666;
    int count = 1;

    while (count != n)
    {
        ++current;
        if (IsValidNumber(current))
            ++count;
    }

    cout << current;
}