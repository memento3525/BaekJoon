#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    vector<queue<int>> v(101);

    int cur;
    for (int i = 0; i < k; ++i)
    {
        cin >> cur;
        q.push(cur);
        v[cur].push(i);
    }

    int ret = 0;
    unordered_set<int> inPluging;
    vector<int> plug(n, -1);

    while (q.size())
    {
        int front = q.front();

        v[front].pop();
        q.pop();

        if (inPluging.find(front) != inPluging.end())
            continue;

        int lowPriorityPlugIndex;
        if (inPluging.size() < n)
        {
            lowPriorityPlugIndex = inPluging.size();
        }
        else
        {
            int max = INT32_MIN;
            int device = 0;
            int minPlugIndex = 0;
            for (int i = 0; i < plug.size(); ++i)
            {
                if (plug[i] == -1) continue;
                if (v[plug[i]].empty())
                {
                    device = plug[i];
                    minPlugIndex = i;
                    break;
                }

                int next = v[plug[i]].front();
                if (next > max)
                {
                    max = next;
                    device = plug[i];
                    minPlugIndex = i;
                }
            }

            lowPriorityPlugIndex = minPlugIndex;
            inPluging.erase(device);
            ++ret;
        }

        plug[lowPriorityPlugIndex] = front;
        inPluging.insert(front);
    }

    cout << ret;
}