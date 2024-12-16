#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int m;
    string wear;
    string wearType;

    unordered_map<string, int> map;

    for (int i = 0; i < n; ++i)
    {
        map.clear();
        cin >> m;

        for (int k = 0; k < m; ++k)
        {
            cin >> wear >> wearType;

            ++map[wearType];
        }

        int sum = 1;
        for (const auto& item : map)
        {
            sum *= (item.second + 1);
        }

        cout << sum - 1 << '\n';
    }
}