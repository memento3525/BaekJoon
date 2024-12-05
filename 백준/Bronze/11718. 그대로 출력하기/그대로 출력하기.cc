#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string temp;
    char delimiter = '\n';

    while (getline(cin, temp, delimiter))
        cout << temp << '\n';
}