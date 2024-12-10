#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l;
    cin >> l;

    string str;
    cin >> str;

    const int m = 1234567891;

    int sum = 0;
    for (int i = 0; i < l; ++i)
    {
        int num = str[i] - 'a' + 1;

        int sqrSum = num;
        for (int k = 0; k < i; ++k)
        {
            sqrSum = sqrSum * 31 % m;
        }

        sum += sqrSum;
    }

    cout << sum % m;
}