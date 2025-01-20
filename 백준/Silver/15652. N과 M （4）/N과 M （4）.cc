#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ret;

void Dfs(int depth, int prev)
{
    if (depth == m)
    {
        for (int i : ret)
            cout << i << ' ';

        cout << '\n';

        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (prev > i) continue;
        ret[depth] = i + 1;
        Dfs(depth + 1, i);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    ret.resize(m);
    Dfs(0, -1);
}