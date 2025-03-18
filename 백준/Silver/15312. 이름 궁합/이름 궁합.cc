#include <iostream>
#include <vector>
using namespace std;

string a, b;
int m[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    vector<int> v(a.size() + b.size(), 0);

    for (int i = 0; i < a.size(); i++)
    {
        v[i * 2] = m[a[i] - 'A'];
        v[i * 2 + 1] = m[b[i] - 'A'];
    }

    int size = v.size();
    while (size != 2)
    {
        for (int i = 0; i < v.size() - 1; ++i)
            v[i] = (v[i] + v[i + 1]) % 10;

        --size;
    }

    cout << v[0] << v[1];
}