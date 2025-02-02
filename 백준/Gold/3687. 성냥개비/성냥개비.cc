#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

const string INFSTR = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
int num[10]{ 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int n;
string dp[101];

string get_min_str(const string& a, const string& b)
{
    if (a.size() < b.size()) return a;
    if (a.size() > b.size()) return b;
    return (a < b ? a : b);
}

string GoMin(int remain)
{
    if (remain == 0) return "";

    string& ret = dp[remain];
    if (ret != INFSTR) return ret;

    for (int i = 0; i < 10; ++i)
    {
        if (remain < num[i]) continue;
        if (remain == n && i == 0) continue;

        ret = get_min_str(ret, (to_string(i) + GoMin(remain - num[i])));
    }

    return ret;
}

string GoMax(int remain)
{
    stringstream ss;

    int k = remain / 2;
    bool hasSeven = remain & 1;
    if (hasSeven)
    {
        ss << '7';
        --k;
    }

    while (k-- > 0)
        ss << '1';

    return ss.str();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        fill(dp, dp + 101, INFSTR);
        cout << GoMin(n) << ' ' << GoMax(n) << '\n';
    }
}