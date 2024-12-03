#include <string>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    while (order != 0)
    {
        int remainder = order % 10;
        if (remainder != 0 && remainder % 3 == 0)
            ++answer;
        
        order /= 10;
    }
    
    return answer;
}