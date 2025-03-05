#include <iostream>
#include <set>
using namespace std;

int n, person, ret, curPerson;
char game;
set<string> s;
string name;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> game;

    if (game == 'Y') person = 1;
    else if (game == 'F') person = 2;
    else person = 3;

    while (n--)
    {
        cin >> name;

        if (s.find(name) != s.end())
            continue;
        
        s.insert(name);
        ++curPerson;

        if (curPerson == person)
        {
            ++ret;
            curPerson = 0;
        }
    }

    cout << ret;
}