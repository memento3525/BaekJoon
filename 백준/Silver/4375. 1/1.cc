#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long targetNum;
    int targetNumLength;
    while (cin >> n)
    {
        targetNum = 1;
        targetNumLength = 1;

        while (true)
        {
            if (targetNum % n == 0)
            {
                cout << targetNumLength << '\n';
                break;
            }

            targetNum = targetNum * 10 + 1;
            targetNum %= n;
            ++targetNumLength;
        }
    }
}