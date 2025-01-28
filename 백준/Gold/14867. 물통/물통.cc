#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int INF = INT32_MAX;
int ma, mb, c, d;
int ret = INF;

set<pair<int, int>> visited;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ma >> mb >> c >> d;

    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    int cnt = -1;
    while (q.size())
    {
        if (ret != INF) break;

        int repeat = q.size();
        ++cnt;

        for (int i = 0; i < repeat; ++i)
        {
            const auto& f = q.front();
            q.pop();
            int a = f.first;
            int b = f.second;
            if (visited.find(f) != visited.end())
                continue;

            visited.insert(f);

            if (a == c && b == d)
            {
                ret = cnt;
                break;
            }

            if (a > 0)
            {
                // E 모두 버린다
                q.push({ 0, b });

                // M a b 가능한 만큼만 붓고 남긴다.
                q.push({ max(0, a + b - mb), min(mb, a + b) });
            }

            if (b > 0)
            {
                // E 모두 버린다
                q.push({ a, 0 });

                // M a b 가능한 만큼만 붓고 남긴다.
                q.push({ min(ma, a + b),max(0, a + b - ma) });
            }

            // F 가득 채운다
            if (a < ma)
                q.push({ ma, b });

            if (b < mb)
                q.push({ a, mb });
        }
    }

    cout << (ret == INF ? -1 : ret);
}