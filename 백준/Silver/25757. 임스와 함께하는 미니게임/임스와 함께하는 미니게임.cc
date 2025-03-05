#include <iostream>
#include <unordered_set>
using namespace std;

int n, person, ret;
unordered_set<string> s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char game;
    cin >> n >> game;

    if (game == 'Y') person = 1;
    else if (game == 'F') person = 2;
    else person = 3;

    s.reserve(n);
    string name;
    while (n--)
    {
        cin >> name;
        s.emplace(name);
    }

    cout << (s.size() / person);
}