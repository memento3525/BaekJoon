#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;

bool Check(const long long mid)
{
    int sum = 0;
    for (const int& i : v)
        sum += i / mid;

    return sum >= n;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;
    v.resize(k);

    int temp;
    for (int i = 0; i < k; ++i)
    {
        cin >> temp;
        v[i] = temp;
    }

    long long lo = 0;
    long long hi = (long long)INT32_MAX + 1;
    while (lo + 1 < hi)
    {
        long long mid = (lo + hi) / 2L;
        if (Check(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << '\n';
}