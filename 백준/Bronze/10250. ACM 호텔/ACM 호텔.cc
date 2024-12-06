#include <iostream>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    int h, w, n;
    while (cin >> h)
    {
        cin >> w >> n;

        int firstNum = (n - 1) % h + 1;
        int lastNum = (n - 1) / h + 1;

        int num = firstNum * 100 + lastNum;
        cout << num << '\n';
    }
}