#include <iostream>
#include <vector>
using namespace std;

int m;
const int MAX_N = 40;
int fibo[MAX_N];
string s = "Messi Gimossi";

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    --m;

    fibo[1] = 5;
    fibo[2] = 13;
    
    for (int i = 3; i < MAX_N; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2] + 1; // 연결 공백 1개 포함

    for (int i = MAX_N - 1; i >= 2; --i)
    {
        if (m >= fibo[i])
            m -= (fibo[i] + 1);
    }

    if (m == 5 || m < 0)
        cout << "Messi Messi Gimossi";
    else
        cout << s[m];
}