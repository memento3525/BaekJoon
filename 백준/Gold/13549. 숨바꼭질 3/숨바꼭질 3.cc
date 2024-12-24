#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int MAX = 100'001;
    int n , k;
    cin >> n >> k;

    vector<int> visited(MAX, 0);

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur != 0)
        {
            int multX = cur * 2;
            while (multX < MAX)
            {
                if (visited[multX] == 0)
                {
                    visited[multX] = visited[cur];
                    q.push(multX);
                }

                multX *= 2;
            }
        }

        for (int nx : { cur - 1, cur + 1 })
        {
            if (nx < 0 || nx >= MAX) continue;

            if (visited[nx] == 0)
            {
                visited[nx] = visited[cur] + 1;
                q.push(nx);
            }
        }
    }

    cout << visited[k] - 1;
}