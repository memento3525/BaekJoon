#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int n = 9;
const int m = 7;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    
    do
    {
        int sum = std::accumulate(v.begin(), v.begin() + m, 0);
        if (sum == 100)
        {
            for (int i = 0; i < m; ++i)
                cout << v[i] << "\n";

            break;
        }

    } while (next_permutation(v.begin(), v.end()));
}