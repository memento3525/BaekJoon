#include <iostream>
#include <vector>
using namespace std;
int visited[100'001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> map(n);
    for (int i = 0; i < n; ++i)
        cin >> map[i];

    long long ret = 0;
    long long a = 0;
    long long b = 0;
    while (a < n)
    {
        if (!visited[map[a]])
        {
            ++visited[map[a]];
            ++a;
        }
        else // 중복이 생겼을 경우 이전 집합은 제외시킴
        {
            ret += (a - b); // 먼저 나온 중복수로 만들 수 있는 경우의 수를 빼주고 포인터를 이동시킴
            --visited[map[b]];
            ++b;
        }
    }

    ret += (long long)(a - b) * (a - b + 1) / 2;
    cout << ret;
}