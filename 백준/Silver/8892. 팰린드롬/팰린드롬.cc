#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int t, k;
string ss[100];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> k;

        for (int i = 0; i < k; ++i)
            cin >> ss[i];
        
        bool find = false;
        for (int a = 0; a < k; ++a)
        {
            if (find) break;
            for (int b = a + 1; b < k; ++b)
            {
                string ab = ss[a] + ss[b];
                string abr = string(ab.rbegin(), ab.rend());
                if (ab == abr)
                {
                    find = true;
                    cout << ab << '\n';
                    break;
                }

                string ba = ss[b] + ss[a];
                string bar = string(ba.rbegin(), ba.rend());
                if (ba == bar)
                {
                    find = true;
                    cout << ba << '\n';
                    break;
                }
            }
        }

        if (!find)
            cout << 0 << '\n';
    }
}