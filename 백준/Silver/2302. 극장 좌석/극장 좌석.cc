#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int fibo[41];
    fibo[0] = 1;
    fibo[1] = 1;
    fibo[2] = 2;

    for (int i = 3; i <= 40; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    int n, m;
    cin >> n >> m;

    int cur = 1;
    int vipTemp;
    vector<int> v;
    for (int i = 0; i < m; ++i)
    {
        cin >> vipTemp;
        v.push_back(vipTemp - cur);
        cur = vipTemp + 1;
    }
    v.push_back(n - cur + 1);

    int ret = 1;
    for (int i : v)
    {
        if (i > 1) // 1개 이하는 경우의 수에 영향을 안줌
            ret *= fibo[i];
    }

    cout << ret;
}