#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    q.push(n);

    bool find = false;
    int cnt = 0;
    while (!find && q.size())
    {
        int size = q.size();
        ++cnt;

        for (int i = 0; i < size; ++i)
        {
            int num = q.front();
            q.pop();

            if (num == 1)
            {
                find = true;
                break;
            }

            if (num % 3 == 0)
                q.push(num / 3);

            if (num % 2 == 0)
                q.push(num / 2);

            q.push(num - 1);
        }
    }

    cout << cnt - 1;
}