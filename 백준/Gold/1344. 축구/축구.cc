#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool pA100, pB100;
double pA, pB;
const int maxPlay = 18;

int isPrime[20];
double dp[19][19][19]; // a, b, 플레이 횟수

double Go(int a, int b, int cnt)
{
    if (cnt == maxPlay)
    {
        if (isPrime[a] || isPrime[b])
            return 1.0;
        else
            return 0.0;
    }

    double& ret = dp[a][b][cnt];
    if (ret > -0.5) return ret;

    ret = 0.0;
    ret += Go(a + 1, b + 1, cnt + 1) * pA       * pB;
    ret += Go(a + 1, b,     cnt + 1) * pA       * (1 - pB);
    ret += Go(a,     b + 1, cnt + 1) * (1 - pA) * pB;
    ret += Go(a,     b    , cnt + 1) * (1 - pA) * (1 - pB);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    pA100 = a == 100;
    pB100 = b == 100;

    if (pA100 && pB100)
    {
        cout << "0.0";
        return 0;
    }

    pA = a / (double)100;
    pB = b / (double)100;

    fill(isPrime, isPrime + 20, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i < 20; ++i)
    {
        for (int j = i + i; j < 20; j += i)
            isPrime[j] = 0;
    }

    fill(&dp[0][0][0], &dp[0][0][0] + 19 * 19 * 19, -1.0);

    cout << std::fixed << std::setprecision(7) << Go(0, 0, 0);
}