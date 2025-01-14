#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n;
ll baseAtk;
vector<int> type;
vector<ll> a;
vector<ll> b;

bool Go(ll mhp)
{
    ll hp = mhp;
    ll atk = baseAtk;

    for (int i = 0; i < n; ++i)
    {
        if (type[i] == 1) // 몬스터
        {
            ll monsterAtk = a[i];
            ll monsterHp = b[i];

            ll attackCnt = (monsterHp - 1) / atk + 1;
            hp -= (attackCnt - 1) * monsterAtk;

            if (hp <= 0)
                return false;
        }
        else // 포션
        {
            atk += a[i];
            hp = min(hp + b[i], mhp);
        }
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> baseAtk;

    type.resize(n);
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> type[i] >> a[i] >> b[i];

    ll left = 1;
    ll right = 1e18;
    ll ret = 1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (Go(mid))
        {
            ret = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ret;
}