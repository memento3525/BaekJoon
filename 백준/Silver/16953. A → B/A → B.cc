#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll a, b;
int ret = INT32_MAX;

void Dfs(ll n, int cnt)
{
    if (n == b)
    {
        ret = min(ret, cnt);
        return;
    }

    if (n > b)
        return;

    Dfs(n * 2, cnt + 1);
    Dfs(n * 10 + 1, cnt + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    Dfs(a, 1);

    if (ret == INT32_MAX)
        cout << -1;
    else
        cout << ret;
}