#include <iostream>
using namespace std;

string dp[251];

// 뒤집어서 계산 
string sum(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);

    int minSize = b.size();

    for (int i = 0; i < minSize; ++i)
    {
        int num = a[i] - '0' + b[i] - '0';
        if (num > 9)
        {
            a[i] = (num - 10) + '0';

            if (i == minSize - 1)
                a.push_back('1');
            else
                a[i + 1]++;
        }
        else
        {
            a[i] = num + '0';
        }
    }

    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    dp[0] = '1';
    dp[1] = '1';
    dp[2] = '3';

    int k = 10007;

    for (int i = 3; i <= 250; ++i)
        dp[i] = sum(sum(dp[i - 2], dp[i - 2]), dp[i - 1]);

    int n;
    while (cin >> n)
    {
        string str = string(dp[n].rbegin(), dp[n].rend());
        cout << str << '\n';
    }
}