#include <iostream>
#include <vector>
using namespace std;

int root;
int erased;
vector<vector<int>> tree;

int DFS(int n)
{
    if (n == erased) return 0;
    if (tree[n].empty() || (tree[n].size() == 1 && tree[n][0] == erased)) return 1;

    int count = 0;
    for (const int& child : tree[n])
        count += DFS(child);

    return count;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p;
    cin >> n;

    tree.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p;
        if (p == -1)
        {
            root = i;
            continue;
        }

        tree[p].push_back(i);
    }

    cin >> erased;
    cout << DFS(root);
}