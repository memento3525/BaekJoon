#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << '0';
        return 0;
    }

    vector<int> v(n);
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v[i] = temp;
    }

    sort(v.begin(), v.end());

    int cuttingCount = round((float)n * (3.0f / 20.0f));

    float sum = accumulate(v.begin() + cuttingCount, v.begin() + v.size() - cuttingCount, 0);
    float average = round(sum / (n - cuttingCount * 2));
    cout << average;
}