#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n, m, temp;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    unordered_set<int> set;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        set.insert(temp);
    }

    int ret = 0;
    while (cin >> temp)
    {
        if (set.find(temp) != set.end())
            set.erase(temp);
        else
            ++ret;
    }

    ret += set.size();
    cout << ret;
}