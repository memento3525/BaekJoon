#include <iostream>
using namespace std;

string s, t;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> s)
    {
        cin >> t;

        int si = 0, ti = 0;
        while (si < s.size() && ti < t.size())
        {
            if (s[si] == t[ti])
                si++;
            ti++;
        }
        
        cout << (si == s.size() ? "Yes" : "No") << '\n';
    }
}