#include <iostream>
using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;

    cout << (a.size() >= b.size() ? "go" : "no");
}