#include <iostream>
using namespace std;

int main(void)
{
    long n[5]{};
    
    for (int i = 0; i < 5; ++i)
        cin >> n[i];

    long sum = 0;

    for (int i = 0; i < 5; ++i)
        sum += ((n[i] * n[i]) % 10);

    cout << sum % 10;
}