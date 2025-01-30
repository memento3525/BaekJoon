#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int h, w;
    cin >> h >> w;

    int m = min(h, w) * 50;
    cout << m;
}