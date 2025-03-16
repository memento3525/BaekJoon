#include <iostream>
#include <string>
using namespace std;

int t;
string s, p;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        int ret = 0;
        cin >> s >> p;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s.find(p, i) == i)
                i += p.size() - 1;

            ++ret;
        }

        cout << ret << '\n';
    }
}