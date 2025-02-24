#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int sum = 90 * (n - 1);
    int temp;
    while (n--)
    {
        cin >> temp;
        sum -= temp;
    }

    cout << sum * 2;
}