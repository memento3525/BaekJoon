#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int require[4];

vector<vector<int>> v;
vector<int> visited;

int minPrice = INT32_MAX;
string ret;

bool Check()
{
    int sum[5]{};

    string str;
    for (int y = 0; y < n; ++y)
    {
        if (visited[y])
        {
            for (int x = 0; x < 5; ++x)
                sum[x] += v[y][x];

            str += to_string(y + 1);
            str += ' ';
        }
    }

    for (int y = 0; y < 4; ++y)
    {
        if (sum[y] < require[y])
            return false;
    }

    if (sum[4] < minPrice)
    {
        minPrice = sum[4];
        ret = str;
    }
    else if (sum[4] == minPrice)
    {
        if (str < ret)
        {
            minPrice = sum[4];
            ret = str;
        }
    }

    return true;
}

void Go(int start)
{
    if (Check())
    {
        return;
    }

    for (int i = start + 1; i < n; ++i)
    {
        if (visited[i]) continue;

        visited[i] = 1;
        Go(i);
        visited[i] = 0;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < 4; ++i)
        cin >> require[i];

    v.resize(n);
    visited.resize(n);
    for (int y = 0; y < n; ++y)
    {
        v[y].resize(5);
        for (int x = 0; x < 5; ++x)
            cin >> v[y][x];
    }

    Go(-1);

    if (ret.empty())
    {
        cout << "-1";
    }
    else
    {
        cout << minPrice << '\n';
        cout << ret;
    }
}