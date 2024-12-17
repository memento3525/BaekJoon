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

    int temp;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;

        if (temp <= k)
            v.emplace_back(temp);
    }

    int remain = k;
    int count = 0;
    vector<int> coins;
    for (int i = v.size() - 1; i >= 0; --i)
    {
        if (v[i] <= remain)
        {
            count += remain / v[i];
            remain %= v[i];

            if (remain == 0)
                break;
        }
    }

    cout << count;
}