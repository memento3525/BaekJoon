#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l;
    string str;
    cin >> l >> str;

    const int m = 1234567891;

    long sum = 0;
    for (int i = 0; i < l; ++i)
    {
        long sqrSum = str[i] - 'a' + 1;
        for (int k = 0; k < i; ++k)
        {
            sqrSum = sqrSum * 31 % m;
        }

        sum += sqrSum;
    }

    cout << sum % m;
}