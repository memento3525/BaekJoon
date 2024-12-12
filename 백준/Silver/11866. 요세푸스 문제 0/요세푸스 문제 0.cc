#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        v.emplace_back(i);
    }

    cout << '<';

    int offset = 0;
    while (v.size() > 1)
    {
        offset = (offset + k - 1) % v.size();
        auto it = v.begin() + offset;

        cout << *it << ", ";
        v.erase(it);
    }

    cout << v.back();
    cout << '>';
}