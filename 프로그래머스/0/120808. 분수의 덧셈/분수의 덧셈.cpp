#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int GCD(int a, int b);

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    
    int child = denom1 * numer2 + denom2 * numer1;
    int parent = denom1 * denom2;
    
    while(true)
    {
        int gcd = child > parent ? GCD(child, parent) : GCD(parent, child);

        if (gcd > 1)
        {
            child /= gcd;
            parent /= gcd;
        }
        else
        {
            break;
        }
    }
    
    return vector<int>{ child, parent };
}

int GCD(int a, int b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}