#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int t, n, m;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    int temp;
    unordered_set<int> set;
    
    for (int ti = 0; ti < t; ++ti)
    {
        set.clear();

        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            set.insert(temp);
        }

        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> temp;
            cout << ((set.find(temp) == set.end()) ? '0' : '1') << '\n';
        }
    }
}