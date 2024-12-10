#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> v;
    string temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v.emplace_back(temp);
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b)
        {
            if (a.size() > b.size()) return false;
            if (a.size() < b.size()) return true;
            return a < b;
        });

    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());

    for (const string& s : v)
    {
        cout << s << '\n';
    }
}