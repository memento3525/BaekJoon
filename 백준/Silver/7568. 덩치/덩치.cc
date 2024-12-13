#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int weight, tall;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weight >> tall;
        v[i] = std::make_pair(weight, tall);
    }

    for (int i = 0; i < n; ++i)
    {
        int count = 1;
        for (int k = 0; k < n; ++k)
        {
            if (i == k) continue;

            const pair<int, int>& a = v[i];
            const pair<int, int>& b = v[k];

            if (a.first < b.first && a.second < b.second)
            {
                ++count;
            }
        }

        cout << count << '\n';
    }
}