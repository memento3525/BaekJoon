#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n + 1);

    for (int i = 2; i < n + 1; ++i)
    {
        for (int k = 2 * i; k < n + 1; k += i)
            ++v[k];
    }

    vector<int> prime;
    int p = 0;
    for (int i = 2; i < n + 1; ++i)
    {
        if (v[i] == 0)
            prime.emplace_back(i);
    }

    int ret = 0;
    if (!prime.empty())
    {
        int left = 0;
        int right = 0;

        int sum = prime[0];
        if (sum == n)
            ++ret;

        while (true)
        {
            if (sum >= n)
            {
                sum -= prime[left];
                ++left;
            }
            else // if (sum < n)
            {
                ++right;

                if (right == prime.size())
                    break;

                sum += prime[right];
            }

            if (sum == n)
                ++ret;
        }
    }

    cout << ret;
}