#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int sum = 1;
    for (int i = n; i > 1; --i)
        sum *= i;

    cout << sum << '\n';
}