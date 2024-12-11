#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, int> _map;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        _map[temp]++;
    }

    int m;
    cin >> m;

    int target;
    for (int i = 0; i < m; ++i)
    {
        cin >> target;
        cout << _map[target] << ' ';
    }
}