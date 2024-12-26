#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> map;
vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int n, m;

long long maxNum = INT64_MIN;
long long minNum = INT64_MAX;

bool IsValid(int index, int b)
{
    int a = v[index];
    if (map[index] == '>')
        return a > b;
    else
        return a < b;
}

void Perm(int depth)
{
    if (depth == m)
    {
        long long n = 0;
        for (int i = 0; i < m; ++i)
        {
            n *= 10;
            n += v[i];
        }

        if (n < minNum)
            minNum = n;

        if (n > maxNum)
            maxNum = n;

        return;
    }

    for (int i = depth; i < 10; ++i)
    {
        if (depth == 0 || IsValid(depth - 1, v[i]))
        {
            swap(v[i], v[depth]);
            Perm(depth + 1);
            swap(v[i], v[depth]);
        }
    }
}

void PrintNum(long long num)
{
    string s = to_string(num);
    if (s.size() < m)
        cout << '0';

    cout << s;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    m = n + 1;

    map.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> map[i];

    Perm(0);

    PrintNum(maxNum);
    cout << '\n';
    PrintNum(minNum);
}