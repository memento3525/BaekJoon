#include <iostream>
using namespace std;

int n;

int main(void)
{
    cin >> n;

    bool isOdd = n & 1;
    n /= 2;
    while (n--)
        cout << "1 2 ";
    
    if (isOdd)
        cout << "3";
}