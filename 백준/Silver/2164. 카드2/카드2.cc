#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    list<int> list;

    for (int i = 1; i <= n; ++i)
    {
        list.emplace_back(i);
    }

    while (list.size() > 1)
    {
        list.pop_front();
        
        int front = list.front();
        list.push_back(front);

        list.pop_front();
    }

    cout << list.front();
}