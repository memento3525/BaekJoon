#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, p;
    cin >> n;

    int size[6]{};
    for (int i = 0; i < 6; ++i)
        cin >> size[i];

    cin >> t >> p;

    int tshirtBundle = 0;
    for (const int& i : size)
    {
        if (i == 0) continue;
        tshirtBundle += (i - 1) / t + 1;
    }

    int penBundle = n / p;
    int penRemain = n % p;

    cout << tshirtBundle << '\n';
    cout << penBundle << " " << penRemain;
}