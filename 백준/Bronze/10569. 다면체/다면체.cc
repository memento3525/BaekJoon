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

    int t, e;
    for (int i = 0; i < n; ++i)
    {
        cin >> t >> e;
        cout << (2 - t + e) << '\n';
    }
}