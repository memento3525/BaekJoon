#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> fsum;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    fsum.resize(n + 1);

    int cur;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cur;
        sum += cur;
        fsum[i] = sum;
    }

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        cout << (fsum[b] - fsum[a - 1]) << '\n';
    }
}