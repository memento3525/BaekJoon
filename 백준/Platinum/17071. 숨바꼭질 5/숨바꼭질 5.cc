#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 500'001;
int visited[2][MAX];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << '0';
        return 0;
    }

    queue<int> q;
    visited[0][a] = 1;
    q.push(a);

    bool finded = false;
    int turn = 1;
    while (!q.empty())
    {
        b += turn;
        if (b > MAX) break;

        if (visited[turn % 2][b])
        {
            finded = true;
            break;
        }

        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int cur = q.front();
            q.pop();
            for (int nx : { cur - 1, cur + 1, cur * 2 })
            {
                if (nx < 0 || nx >= MAX) continue;
                if (visited[turn % 2][nx]) continue;

                // 이전 턴은 홀짝이 반대라서 turn + 1 mod 연산.
                visited[turn % 2][nx] = visited[(turn + 1) % 2][cur] + 1;

                if (nx == b)
                {
                    finded = true;
                    break;
                }
                q.push(nx);
            }

            if (finded) break;
        }

        if (finded) break;
        ++turn;
    }

    if (finded) 
        cout << turn;
    else 
        cout << "-1";
}