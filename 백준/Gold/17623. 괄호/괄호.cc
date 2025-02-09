#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9;
int n;
char brace[6] = { '(', ')', '{', '}', '[', ']' };
map<char, char> mp;
string dp[1001];

bool Check(string before, string after)
{
    if (before == "" && after == "") return false;
    if (before == "") return true;
    if (before.size() == after.size()) return after < before;
    return after.size() < before.size();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 6; ++i)
        mp[i + '1'] = brace[i];

    dp[1] = "12"; // ()
    dp[2] = "34"; // {}
    dp[3] = "56"; // []

    for (int idx = 1; idx <= 1000; ++idx)
    {
        // 한 겹을 더 만드는 경우
        // 만들려는 수가 n의 배수인 경우에는 인수분해하듯 나눠준다.
        if (idx % 2 == 0 && Check(dp[idx], '1' + dp[idx / 2] + '2')) dp[idx] = '1' + dp[idx / 2] + '2';
        if (idx % 3 == 0 && Check(dp[idx], '3' + dp[idx / 3] + '4')) dp[idx] = '3' + dp[idx / 3] + '4';
        if (idx % 5 == 0 && Check(dp[idx], '5' + dp[idx / 5] + '6')) dp[idx] = '5' + dp[idx / 5] + '6';

        // 옆에 나란히 붙이는 경우
        for (int i = 1; i <= idx; ++i)
        {
            if (Check(dp[idx], dp[i] + dp[idx - i]))
                dp[idx] = dp[i] + dp[idx - i]; // 갱신
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        
        for (char c : dp[n])
            cout << mp[c];

        cout << '\n';
    }
}