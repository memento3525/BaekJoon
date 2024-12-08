#include <iostream>
using namespace std;
int GCD(int a, int b);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int gcd = GCD(a, b);
    int lcm = a * b / gcd;

    cout << gcd << '\n' << lcm;
}


int GCD(int a, int b)
{
    int temp = 0;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}