#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    
    while (cin >> n)
    {
        cin >> s;
        cout << s / (n + 1) << '\n';
    }
}