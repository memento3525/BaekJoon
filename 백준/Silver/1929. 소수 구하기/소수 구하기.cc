#include <iostream>
using namespace std;

bool IsPrime(int n)
{
    if (n == 1) return false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; ++i)
    {
        if (IsPrime(i))
            cout << i << '\n';
    }
}