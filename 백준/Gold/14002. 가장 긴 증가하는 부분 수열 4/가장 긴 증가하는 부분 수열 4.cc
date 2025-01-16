#include <iostream>
#include <vector>
using namespace std;

int n, temp, len;
vector<int> v;
vector<pair<int, int>> ans;
const int MAX = 1e9 + 1;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n, MAX);
    ans.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        auto lowerPos = lower_bound(v.begin(), v.end(), temp);
        int _pos = (int)(lowerPos - v.begin());
        if (*lowerPos == MAX)
            ++len;

        *lowerPos = temp;
        ans[i] = { _pos , temp };
    }

    cout << len << '\n';

    vector<int> ret;
    for (int i = n - 1; i >= 0; --i)
    {
        if (ans[i].first == len - 1)
        {
            ret.push_back(ans[i].second);
            --len;
        }
    }
    
    auto it = ret.rbegin();
    while (it != ret.rend())
    {
        cout << *it << ' ';
        ++it;
    }
}