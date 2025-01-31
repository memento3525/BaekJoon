#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, w, h;
    cin >> n >> w >> h;

    int l;
    int max_sqr = w * w + h * h;
    for (int i = 0; i < n; ++i)
    {
        cin >> l;
        cout << ((l * l <= max_sqr) ? "DA" : "NE") << '\n';
    }
}