#include <iostream>

using namespace std;

int main(void)
{
    char n;
    string str;
    while (cin >> n)
        str += n;

    if (str == "12345678")
        cout << "ascending";
    else if (str == "87654321")
        cout << "descending";
    else
        cout << "mixed";
}