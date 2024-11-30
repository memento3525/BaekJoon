#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0;
    int mult = 1;
    while (mult <= n)
    {
        ++answer;
        mult *= answer;
    }
    
    return answer - 1;
}