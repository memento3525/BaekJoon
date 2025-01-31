#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, w[31];
vector<int> v, v2;

void Go(int here, int end, vector<int> &v, int sum)
{
    if (sum > c) 
        return;

    if (here > end)
    {
        v.push_back(sum);
        return;
    }

    Go(here + 1, end, v, sum + w[here]); // 담는 경우
    Go(here + 1, end, v, sum); // 안담는 경우
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; ++i)
        cin >> w[i];

    Go(0, n / 2 - 1, v, 0);
    Go(n / 2, n - 1, v2, 0);
    
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    int ret = 0;
    for (int i : v)
    {
        // 다른 주머니의 모든 가능한 경우의 수와 합친다.
        int max_addWeight = c - i;
        ret += ((int)(upper_bound(v2.begin(), v2.end(), max_addWeight) - v2.begin()));
    }

    cout << ret;
}