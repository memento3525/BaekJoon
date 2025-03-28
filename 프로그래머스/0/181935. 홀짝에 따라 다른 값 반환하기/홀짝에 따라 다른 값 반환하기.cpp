#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if (n % 2 == 0)
    {
        while (n >= 2)
        {
            answer += n * n;
            n -= 2;
        }
    }
    else
    {
        while (n >= 1)
        {
            answer += n;
            n -= 2;
        }
    }
    
    return answer;
}