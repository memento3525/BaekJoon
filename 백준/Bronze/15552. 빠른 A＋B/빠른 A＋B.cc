#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}
