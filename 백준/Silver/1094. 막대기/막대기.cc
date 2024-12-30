#include <iostream>
using namespace std;

int main(void)
{
    int x;
    cin >> x;

    int ret = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (x & (1 << i))
            ++ret;
    }
    
    cout << ret;
}