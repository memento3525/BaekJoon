#include <iostream>
#include <vector>
using namespace std;

const int NM = 2501;
const int INF = INT32_MAX;
string str;

char arr[NM];
int dp[NM][NM];
int dp2[NM];

int Check(int a, int size)
{
    if (size == 1) return 1;
    if ((size == 2) && arr[a] == arr[a + 1]) return 1;
    if (arr[a] != arr[a + size - 1]) return 0;

    int& ret = dp[a][size];
    if (ret != -1) return ret;

    ret = Check(a + 1, size - 2);
    return ret;
}

int Go(int start)
{
    if (start == str.size()) return 0;

    int& ret = dp2[start];
    if (ret != INF) return ret;

    for (int size = 1; start + size <= str.size(); ++size)
    {
        if (Check(start, size))
            ret = min(ret, Go(start + size) + 1);
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0], &dp[0][0] + NM * NM, -1);
    fill(dp2, dp2 + NM, INF);

    cin >> str;

    for (int i = 0; i < str.size(); ++i)
        arr[i] = str[i];

    cout << Go(0);
}