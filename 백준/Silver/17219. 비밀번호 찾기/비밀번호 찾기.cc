#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string site;
    string password;

    unordered_map<string, string> map;
    for (int i = 0; i < n; ++i)
    {
        cin >> site >> password;
        map[site] = password;
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> site;
        cout << map[site] << '\n';
    }
}