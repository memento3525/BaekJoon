#include <iostream>
#include <math.h>
using namespace std;

int t;
string s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s;

        int n = sqrt(s.size());

        string origin;
        for (int x = n; x > 0; x--)
        {
            for (int y = 0; y < n; y++)
            {
                int index = y * n + x - 1;
                origin += s[index];
            }
        }
        cout << origin << '\n';
    }
}