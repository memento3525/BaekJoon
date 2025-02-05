#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
const int MAX_N = 75001;
const int maxXY = 1'000'000'000;

int n, x, y;
int island_y[MAX_N];
int island_x[MAX_N];

vector<pair<int, int>> a;
vector<int> _y;
vector<int> tree;

int find_index(vector<int>& v, int value)
{
    int low = 0;
    int high = v.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == value)
        {
            return mid;
        }
        else if (v[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// 펜윅트리 합
ll sum(int i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += (ll)tree[i];
        i -= (i & -i);
    }
    return ret;
}

// 펜윅트리 업데이트
void update(int index, int value)
{
    int i = index;
    while (i <= n)
    {
        tree[i] += value;
        i += (i & -i); // 켜져있는 가장 작은 비트
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        a.clear();
        _y.clear();
        tree.clear();

        tree.resize(n + 1);

        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            a.push_back({ x, -y });
            _y.push_back(-y);
        }

        sort(a.begin(), a.end());
        sort(_y.begin(), _y.end()); // -10억 ~ 10억 좌표를 압축한다

        ll ret = 0;
        update(find_index(_y, a[0].second) + 1, 1);

        for (int i = 1; i < n; ++i)
        {
            int index = find_index(_y, a[i].second) + 1;
            ret += sum(index);
            update(index, 1);
        }

        cout << ret << '\n';
    }
}