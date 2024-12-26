#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int depth, nodeSize;
queue<int> q;
vector<int> a;

void Go(int i)
{
    if (2 * i + 1 < nodeSize)
        Go(2 * i + 1);

    a[i] = q.front();
    q.pop();

    if (2 * i + 2 < nodeSize)
        Go(2 * i + 2);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> depth;

    int temp;
    while (cin >> temp)
        q.push(temp);

    nodeSize = q.size();
    a.resize(nodeSize);

    Go(0);

    int i = 0;
    int pot = 1;
    while (i < nodeSize)
    {
        for (int x = 0; x < pot; ++x)
        {
            cout << a[i] << " ";
            ++i;
        }

        pot *= 2;
        cout << '\n';
    }
}