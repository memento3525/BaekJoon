#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, m, k;
vector<ll> tree;
vector<ll> num;

void Update(int i, ll value)
{
    while (i < tree.size())
    {
        tree[i] += value;
        i += (i & -i);
    }
}

ll Sum(int i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

ll Query(int left, int right)
{
    return Sum(right) - Sum(left - 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    tree.resize(n + 1);
    num.resize(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
        Update(i, num[i]);
    }

    int a, b;
    ll c;
    for (int i = 0; i < m + k; ++i)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            ll diff = c - num[b];
            Update(b, diff);
            num[b] = c;
        }
        else if (a == 2)
        {
            cout << Query(b, c) << '\n';
        }
    }
}