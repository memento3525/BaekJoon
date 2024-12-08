#include <iostream>

using namespace std;
static bool isPrime(int n);

int main(void)
{
    int n;
    cin >> n;

    int temp;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (isPrime(temp))
            ++count;
    }

    cout << count;
}

static bool isPrime(int n)
{
    if (n == 1) return false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}