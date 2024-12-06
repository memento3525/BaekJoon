#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << '\n';

    string str = to_string(a) + to_string(b);
    cout << std::stoi(str) - c;
}