#include <iostream>
#include <queue>
using namespace std;

struct Compare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first > b.first;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    int c;
    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        if (c == 0)
        {
            if (pq.empty())
            {
                cout << '0' << '\n';
            }
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push({ abs(c), c });
        }
    }
}