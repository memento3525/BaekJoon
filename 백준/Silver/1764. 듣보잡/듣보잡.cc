#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<string> set;

    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        set.insert(str);
    }

    vector<string> v;
    int ret = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> str;
        if (set.find(str) != set.end())
        {
            ++ret;
            v.emplace_back(str);
        }
    }

    sort(v.begin(), v.end());

    cout << ret << '\n';
    for (const string& s : v)
        cout << s << '\n';
}