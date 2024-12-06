#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int r;
    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> r;
        cin >> str;

        for (const char& c : str)
            cout << string(r, c);

        cout << '\n';
    }
}