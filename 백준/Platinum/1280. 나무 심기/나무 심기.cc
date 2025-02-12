#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
const int MAX_N = 200000;
const ll mod = 1'000'000'007;
vector<ll> tree_cnt(MAX_N + 1); // 트리의 갯수
vector<ll> tree_sum(MAX_N + 1); // 트리의 합

ll Sum(vector<ll>& tree, int i)
{
    ll sum = 0;

    while (i > 0)
    {
        sum += tree[i];
        i -= (i & -i);
    }

    return sum;
}

ll QuerySum(vector<ll>& tree, int left, int right)
{
    if (left > right) return 0;
    return Sum(tree, right) - Sum(tree, left - 1);
}

void Update(vector<ll>& tree, int i, ll value)
{
    while (i <= MAX_N)
    {
        tree[i] += value;
        i += (i & -i);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int num;
    ll ret = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        ++num;

        if (i != 1)
        {
            // 다음 나무가 오른쪽이라면
            // ((이전까지의 나무의 갯수 + 1) x 심으려는 나무의 위치) - 이전 나무들의 위치들
            // 심으려는 위치를 기준으로 온전한 바 형태의 거리가 n개 만들어지고
            // 지금 심으려는 위치는 이전 나무에서 온전한 거리를 빼면 구해진다.
            ll left = num * QuerySum(tree_cnt, 1, num - 1) - QuerySum(tree_sum, 1, num - 1);

            // 다음 나무가 왼쪽이라면
            // ((이전까지의 나무의 갯수 + 1) x 심으려는 나무의 위치) - (이전 나무들의 위치들 - 현재위치)
            ll right = QuerySum(tree_sum, num + 1, MAX_N) - num * QuerySum(tree_cnt, num + 1, MAX_N);

            ret *= (left + right) % mod;
            ret %= mod;
        }

        Update(tree_cnt, num, 1);
        Update(tree_sum, num, num);
    }

    cout << ret;
}