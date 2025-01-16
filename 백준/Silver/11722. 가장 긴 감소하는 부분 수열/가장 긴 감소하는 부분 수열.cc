#include <iostream>
#include <vector>
using namespace std;

int n, temp, len;
vector<int> input;
vector<int> v;
const int MAX = (1e9 + 1);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    input.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> input[i];

    v.resize(n, MAX);
    for (int i = 0; i < n; ++i)
    {
        int temp = input[n - 1 - i];
        auto lowerPos = lower_bound(v.begin(), v.end(), temp);
        if (*lowerPos == MAX)
            ++len;

        *lowerPos = temp;
    }

    cout << len;
}