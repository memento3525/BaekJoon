#include <string>
#include <vector>

using namespace std;
int GCD(int a, int b);

int solution(int n) 
{
    return n / GCD(6, n);
}

int GCD(int a, int b)
{
    if (b == 0) return a;
    else return GCD(b, a % b);
}
