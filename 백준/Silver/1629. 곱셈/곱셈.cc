#include <iostream>
using namespace std;

int a, b, c;

long long Mult(long long n)
{
    if (n == 1)
        return a % c;

    long long result = Mult(n / 2);
    result = (result * result) % c;

    if (n % 2 == 1)
        result = (result * a) % c;
    
    return result;
}

int main(void)
{
    cin >> a >> b >> c;
    cout << Mult(b);
}