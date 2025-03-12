#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s, f;
int n, ret;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> n;

    while (n--)
    {
        cin >> f;
        f += f;

        if (f.find(s) != string::npos)
            ret++;
    }

    cout << ret;
}