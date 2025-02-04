#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int STR[51], INT[51], PNT[51];
int dp[1001][1001];
int visited[1001];

int Go(int _str, int _int)
{
    int& ret = dp[_str][_int];
    if (ret != -1) return ret;

    ret = 0;
    int point = 0;

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        if (STR[i] <= _str || INT[i] <= _int)
        {
            ++ret; // 재귀 쪽의 체크를 위해 방문과 상관없이 ret을 올린다.
            if (!visited[i])
            {
                visited[i] = true;
                point += PNT[i];
                v.push_back(i);
            }
        }
    }

    // 얻은 포인트를 분배했을 때, 모든 경우의 수
    for (int p = 0; p <= point; ++p)
    {
        int nSTR = min(1000, _str + p);
        int nINT = min(1000, _int + point - p);
        ret = max(ret, Go(nSTR, nINT));
    }

    // 다음 경우의 수에 영향을 미치지않도록 풀어줌
    for (int here : v)
        visited[here] = false;

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0], &dp[0][0] + 1001 * 1001, -1);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> STR[i] >> INT[i] >> PNT[i];

    cout << Go(1, 1);
}