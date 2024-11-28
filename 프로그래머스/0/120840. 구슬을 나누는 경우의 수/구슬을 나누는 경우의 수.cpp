#include <string>
#include <vector>

using namespace std;
__int128 fac(int k);

int solution(int n, int m) {
    return fac(n) / (fac(n - m) * fac(m));
}

__int128 fac(int k)
{
    __int128 result = 1;
    while (k >= 1)
    {
        result *= k;
        --k;
    }
    return result;
}