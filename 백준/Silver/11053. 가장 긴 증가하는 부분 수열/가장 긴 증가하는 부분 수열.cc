#include <iostream>
#include <vector>
using namespace std;

int n, temp, len;
vector<int> v;
const int MAX = 1001;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n, MAX);

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        auto lowerPos = lower_bound(v.begin(), v.end(), temp);
        int _pos = (int)(lowerPos - v.begin());
        if (*lowerPos == MAX)
            ++len;

        *lowerPos = temp;
    }

    cout << len << '\n';
}