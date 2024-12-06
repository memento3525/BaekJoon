#include <iostream>
using namespace std;

int main(void)
{
    int result = 0;
    string temp;
    while (cin >> temp)
        ++result;
    
    cout << result;
}