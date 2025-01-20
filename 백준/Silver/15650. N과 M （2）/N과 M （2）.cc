#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<int> pick(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;

    for (int i = 0; i < m; ++i)
        pick[i] = 1;

    do
    {
        for (int i = 0; i < n; ++i)
        {
            if (pick[i] == 1)
                cout << v[i] << ' ';
        }
        cout << '\n';

    } while (prev_permutation(pick.begin(), pick.end()));
}
