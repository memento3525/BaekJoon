#include <iostream>
#include <string>
using namespace std;

int n, ret;
string s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> s;

        int remain = stoi(s.substr(2, s.size() - 1));
        if (remain <= 90)
            ++ret;
    }

    cout << ret;
}