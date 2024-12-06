#include <iostream>
using namespace std;

int main(void)
{
    string str; 
    cin >> str;

    int size = 'z' - 'a';
    for (int i = 0; i <= size; ++i)
    {
        char c = 'a' + i;
        auto pos = str.find(c);
        cout << (int)pos << ' ';
    }
}