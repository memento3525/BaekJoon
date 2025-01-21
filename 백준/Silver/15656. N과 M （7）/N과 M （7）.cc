#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;
vector<int> ret;

void Dfs(int depth)
{
    if (depth == m)
    {
        for (int i : ret)
            cout << nums[i] << ' ';

        cout << '\n';
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        ret[depth] = i;
        Dfs(depth + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    nums.resize(n);
    ret.resize(m);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    Dfs(0);
}