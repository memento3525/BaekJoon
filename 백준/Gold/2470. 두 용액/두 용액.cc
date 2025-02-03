#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    int left = 0;
    int right = n - 1;

    int minDist = 2'000'000'001;
    int ret[2]{ left, right };

    while (left < right)
    {
        int sum = v[left] + v[right];

        if (abs(sum) < minDist)
        {
            minDist = abs(sum);
            ret[0] = v[left];
            ret[1] = v[right];
        }

        if (sum == 0)
            break;

        if (sum < 0)
            ++left;
        else // sum > 0
            --right;
    }

    cout << ret[0] << ' ' << ret[1];
}