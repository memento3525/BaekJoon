#include <iostream>
#include <unordered_set>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_set<int> _set;

    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        _set.insert(temp);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> temp;

        auto it = _set.find(temp);
        cout << (it == _set.end() ? '0' : '1') << '\n';
    }
}