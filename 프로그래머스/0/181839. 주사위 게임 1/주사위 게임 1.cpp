#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b) {
    
    int oddCount = (a & 1) + (b & 1); 
    
    if (oddCount == 2) return a * a + b * b;
    if (oddCount == 1) return 2 * ( a + b );
    else return abs(a - b);
}