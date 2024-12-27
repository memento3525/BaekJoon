#include <iostream>
#include <vector>

using namespace std;

int map[101][101];
int visited[101];
int ret = 1;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int a, b;
    for (int i = 0; i < k; ++i)
    {
        cin >> a >> b;

        map[a][b] = 1;
        map[b][a] = 1;
    }

    vector<int> v;
    v.emplace_back(1);
    visited[1] = 1;

    while (!v.empty())
    {
        int a = v.back();
        v.pop_back();

        for (int b = 1; b < n + 1; ++b)
        {
            if (visited[b]) continue;

            if (map[a][b])
            {
                v.emplace_back(b);
                visited[b] = 1;
                ++ret;
            }
        }
    }

    cout << ret - 1;
}