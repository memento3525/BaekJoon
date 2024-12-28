#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> bits(n);

    string str;
    for (int y = 0; y < n; ++y)
    {
        cin >> str;

        for (int x = 0; x < str.size(); ++x)
        {
            if (str[x] == 'T')
                bits[y] |= (1 << x);
        }
    }

    int ret = INT32_MAX;

    // 비트 조합
    for (int y = 0; y < (1 << n); ++y)
    {
        // 비트포함되어있다면 뒤집기
        for (int x = 0; x < n; ++x)
        {
            if (y & (1 << x))
                bits[x] = ~bits[x];
        }

        // 세로축 합 구하기
        int sum = 0;
        for (int k = 0; k < n; ++k)
        {
            int xSum = 0;
            for (const int& bit : bits)
            {
                if (bit & (1 << k))
                    ++xSum;
            }
            sum += min(xSum, n - xSum);
        }

        if (sum < ret)
            ret = sum;

        // 복구
        for (int x = 0; x < n; ++x)
        {
            if (y & (1 << x))
                bits[x] = ~bits[x];
        }
    }

    cout << ret;
}