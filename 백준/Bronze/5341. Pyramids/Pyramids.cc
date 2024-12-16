#include <iostream>
using namespace std;

int main(void)
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        int sum = 0;
        for (int i = 1; i <= n; ++i)
            sum += i;

        cout << sum << '\n';
    }
}