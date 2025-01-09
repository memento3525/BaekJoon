#include <iostream>
#include <vector>
using namespace std;

int n;
int _max = INT32_MIN;
int _min = INT32_MAX;
vector<int> v;
vector<int> op(4);

void Go(int start, int opIndex, int num)
{
    if (opIndex == 0)      num += v[start];
    else if (opIndex == 1) num -= v[start];
    else if (opIndex == 2) num *= v[start];
    else if (opIndex == 3) num /= v[start];

    if (start == n - 1)
    {
        if (num < _min)
            _min = num;

        if (num > _max)
            _max = num;

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (op[i] == 0) continue;

        --op[i];
        Go(start + 1, i, num);
        ++op[i];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    --n;

    int start;
    cin >> start;

    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < 4; ++i)
        cin >> op[i];

    Go(-1, -1, start);

    cout << _max << '\n' << _min;
    return 0;
}