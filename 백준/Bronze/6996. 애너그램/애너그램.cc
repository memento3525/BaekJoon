#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int t;
string a, b;
vector<char> va, vb;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    va.reserve(100);
    vb.reserve(100);
    
    while (t--)
    {
        cin >> a >> b;
        cout << a << " & " << b << " are ";

        if (a.size() != b.size())
        {
            cout << "NOT ";
        }
        else
        {
            va.clear();
            va.resize(a.size());
            vb.clear();
            vb.resize(b.size());

            for (int ai = 0; ai < a.size(); ai++)
                va[ai] = a[ai];

            for (int bi = 0; bi < b.size(); bi++)
                vb[bi] = b[bi];

            sort(va.begin(), va.end());
            sort(vb.begin(), vb.end());

            for (int i = 0; i < va.size(); i++)
            {
                if (va[i] != vb[i])
                {
                    cout << "NOT ";
                    break;
                }
            }
        }

        cout << "anagrams." << '\n';
    }
}