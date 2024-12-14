#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int result = 0; // 제거한 0 수
    long long fac = 1;
    for (int i = 2; i <= n; ++i)
    {
        fac *= i;

        while (fac % 10 == 0)
        {
            fac /= 10;
            ++result;
        }

        fac %= 100000; // 앞부분 삭제
    }

    cout << result;
}