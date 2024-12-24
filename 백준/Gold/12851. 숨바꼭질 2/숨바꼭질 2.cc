#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , k;
    cin >> n >> k;

    vector<int> visited(100'001, 0);
    vector<int> cnt(100'001, 0);

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nx : { cur - 1, cur + 1, cur * 2 })
        {
            if (nx < 0 || nx >= 100'001) continue;

            if (visited[nx] == 0)
            {
                visited[nx] = visited[cur] + 1;
                cnt[nx] += cnt[cur];
                q.push(nx);
            }
            else if(visited[nx] == visited[cur] + 1)
            {
                cnt[nx] += cnt[cur];
            }
        }
    }

    cout << visited[k] - 1 << '\n';
    cout << cnt[k];
}