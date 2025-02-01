#include <iostream>
using namespace std;

int main(void)
{
    int n, t, e;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t >> e;
        cout << (2 - t + e) << '\n';
    }
}