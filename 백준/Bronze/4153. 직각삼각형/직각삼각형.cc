#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c;

    while (true)
    {
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
            break;

        int aa = a * a;
        int bb = b * b;
        int cc = c * c;
        
        if (aa == bb + cc || bb == aa + cc || cc == aa + bb)
        {
            cout << "right" << '\n';
        }
        else
        {
            cout << "wrong" << '\n';
        }
    }
}