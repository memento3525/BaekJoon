#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int remain = i;
        int sum = i;
        while (remain > 0)
        {
            sum += remain % 10;
            remain /= 10;
        }
        
        if (sum == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << '0';
}