#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cout << string(n - i, ' ') << string(i, '*') << '\n';
}