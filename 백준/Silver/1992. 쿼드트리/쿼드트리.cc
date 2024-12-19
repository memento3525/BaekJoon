#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> map;

string Quad(int size, int y, int x)
{
    char c = map[y][x];

    if (size == 1)
        return string(1, c);

    string result = "";

    for (int i = y; i < y + size; ++i)
    {
        for (int k = x; k < x + size; ++k)
        {
            if (c != map[i][k])
            {
                result += '(';

                int halfSize = size / 2;
                result += Quad(halfSize, y, x);
                result += Quad(halfSize, y, x + halfSize);
                result += Quad(halfSize, y + halfSize, x);
                result += Quad(halfSize, y + halfSize, x + halfSize);

                result += ')';
                return result;
            }
        }
    }

    return string(1, c);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map.resize(n);

    string str;
    for (int y = 0; y < n; ++y)
    {
        cin >> str;

        map[y] = vector<char>(n);

        for (int x = 0; x < n; ++x)
            map[y][x] = str[x];
    }

    cout << Quad(n, 0, 0);
}