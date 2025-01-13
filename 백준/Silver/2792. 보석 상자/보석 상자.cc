#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int ret = INT32_MAX;

bool IsPossible(int mid)
{
    int remain = n;
    for (int i : v)
    {
        int cnt = ((i - 1) / mid) + 1;
        remain -= cnt;
    }

    return remain >= 0;
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

    int left = 1;
    int right = INT32_MAX;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (IsPossible(mid))
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