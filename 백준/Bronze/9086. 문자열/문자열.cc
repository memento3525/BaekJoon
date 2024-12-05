#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        cout << str[0] << str[str.size() - 1] << '\n';
    }
}