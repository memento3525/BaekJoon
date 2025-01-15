#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n, m;
vector<ll> v;

// mid시간안에 n명을 태울 수 있느냐?
bool Check(ll mid)
{
    ll cnt = m; // 최초엔 대기열이 없다
    for (ll i : v)
    {
        cnt += mid / i;
        if (cnt >= n)
            return true;
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    v.resize(m);

    for (int i = 0; i < m; ++i)
        cin >> v[i];

    if (n <= m)
    {
        cout << n;
        return 0;
    }

    // 특정시간 mid 일때 n명 태우기
    ll left = 1;
    ll right = 1e18;
    ll retTime = 0;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (Check(mid))
        {
            retTime = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    // mid - 1 시간일 떄의 인원
    ll cnt = m; // 최초엔 대기열이 없다
    for (int i = 0; i < m; ++i)
        cnt += (retTime - 1) / v[i];

    // mid 시간일 때의 인원
    for (int i = 0; i < m; ++i)
    {
        if (retTime % v[i] == 0)
            ++cnt;

        if (cnt == n) 
        {
            cout << (i + 1);
            return 0;
        }
    }

    return 0;
}