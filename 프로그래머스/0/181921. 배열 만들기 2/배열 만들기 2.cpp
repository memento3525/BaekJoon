#include <string>
#include <vector>

using namespace std;
int GCD(int a, int b);

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (; l <= r; ++l)
    {
        if (l % 5 != 0) continue;
        
        bool isFail = false;
        int cur = l;
        while (cur != 0)
        {
            int remain = cur % 10;
            if (remain != 0 && remain != 5)
            {
                isFail = true;
                break;
            }

            cur /= 10; // 다음 자릿수
        }
        
        if (!isFail)
            answer.push_back(l);
    }
    
    if (answer.empty())
        answer.push_back(-1);
    
    return answer;
}