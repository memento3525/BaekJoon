#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    
    int sameCount = 0;
    if (a == b) ++sameCount;
    if (b == c) ++sameCount;
    if (a == c) ++sameCount;
    
    int answer = a + b + c;
    
    if (sameCount == 0)
        return answer;
    
    answer *= (a * a + b * b + c * c);
    
    if (sameCount == 1)
        return answer;
    
    answer *= (a * a * a + b * b * b + c * c * c);
    
    return answer;
}