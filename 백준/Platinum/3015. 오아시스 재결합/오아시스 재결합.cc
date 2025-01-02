#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    stack<pair<int, int>> s;

    int cur;
    long long ret = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> cur;

        int sameCnt = 1;
        while (s.size() && cur >= s.top().first)
        {
            ret += s.top().second;

            if (s.top().first == cur)
                sameCnt = s.top().second + 1;
            else
                sameCnt = 1;

            s.pop();
        }

        if (s.size())
            ++ret;

        s.push({ cur, sameCnt });
    }

    cout << ret;
}