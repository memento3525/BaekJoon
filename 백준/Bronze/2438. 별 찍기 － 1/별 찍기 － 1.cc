#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        string s(i, '*');
        cout << s << '\n';
    }
}
