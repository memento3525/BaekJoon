#include <iostream>
#include <deque>
using namespace std;

bool IsAnyHighPriority(const deque<pair<int, bool>>& q, const pair<int, bool>& front)
{
    if (q.empty())
        return false;

    for (auto it = q.begin(); it != q.end(); ++it)
    {
        if (front.first < (*it).first)
            return true;
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;

    int n, m, priority;
    for (int i = 0; i < size; ++i)
    {
        deque<pair<int, bool>> q; // <우선순위, 타겟여부>

        cin >> n >> m;

        for (int k = 0; k < n; ++k)
        {
            cin >> priority;
            q.emplace_back(make_pair(priority, k == m));
        }

        int count = 0;
        while (!q.empty())
        {
            const pair<int, int>& front = q.front();
            q.pop_front();
            if (IsAnyHighPriority(q, front))
            {
                q.emplace_back(front);
            }
            else
            {
                ++count;
                if (front.second)
                {
                    cout << count << '\n';
                    break;
                }
            }
        }
    }
}