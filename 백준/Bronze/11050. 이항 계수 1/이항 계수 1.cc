#include <iostream>
using namespace std;

int Combi(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return Combi(n - 1, r - 1) + Combi(n - 1, r);
    }
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    cout << Combi(n, k);
}