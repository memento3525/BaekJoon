#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

const string INFSTR = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
const int INF = 1e9;
int num[10]{ 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int n;

int dp[101][51]; // 사용한 성냥, 인덱스
vector<int> v;
vector<vector<int>> retV;
int curMin;

int GoMin(int remain, int index) // 최소 사이즈 먼저찾음
{
    if (remain == 0)
    {
        if (v.size() < curMin)
        {
            retV.clear();
            curMin = v.size();
            retV.push_back(v);
        }
        else if (v.size() == curMin)
        {
            retV.push_back(v);
        }

        return 0;
    }

    int& ret = dp[remain][index];
    if (ret != INF) return ret;

    for (int i = 0; i < 10; ++i)
    {
        if (index == 0 && i == 0) continue;
        if (remain < num[i]) continue;
        if (remain - num[i] == 1) continue;

        v.push_back(i);
        ret = min(ret, GoMin(remain - num[i], index + 1) + 1);
        v.pop_back();
    }

    return ret;
}

string GetMin(int n)
{
    fill(&dp[0][0], &dp[0][0] + 101 * 51, INF);
    curMin = INF;
    v.clear();

    GoMin(n, 0);

    string minStr = INFSTR;
    for (auto& item : retV)
    {
        sort(item.begin(), item.end());
        if (item[0] == 0)
        {
            if (n == 1) continue;

            int notZeroIndex = -1;

            for (int i = 1; i < item.size(); ++i)
            {
                if (item[i] != 0)
                {
                    notZeroIndex = i;
                    break;
                }
            }

            if (notZeroIndex == -1) continue;

            swap(item[0], item[notZeroIndex]);
        }

        stringstream ss;

        for (auto c : item)
            ss << c;

        string finalStr = ss.str();
        if (finalStr < minStr)
            minStr = finalStr;
    }

    return minStr;
}

string GetMax(int remain)
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
        cout << GetMin(n) << ' ' << GetMax(n) << '\n';
    }
}