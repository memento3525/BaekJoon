#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    deque<int> d;

    int temp;
    int sum = 0;
    for (int i = 0; i < k; ++i)
    {
        cin >> temp;
        sum += temp;

        d.emplace_back(temp);
    }

    int maxSum = sum;
    while (cin >> temp)
    {
        sum -= d.front();
        d.pop_front();

        sum += temp;
        d.emplace_back(temp);

        if (sum > maxSum)
            maxSum = sum;
    }

    cout << maxSum;
}