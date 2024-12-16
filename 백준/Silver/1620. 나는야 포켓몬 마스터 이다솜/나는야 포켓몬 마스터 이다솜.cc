#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<string> v(n + 1);
    unordered_map<string, int> map;

    string temp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        v[i] = temp;
        map[temp] = i;
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> temp;

        if (isdigit(temp[0]))
        {
            int number = stoi(temp);
            cout << v[number] << '\n';
        }
        else
        {
            cout << map[temp] << '\n';
        }
    }
}