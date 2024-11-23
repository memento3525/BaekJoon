#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    
    int answer = 0;
    bool anyChange = true;
    while (anyChange)
    {
        anyChange = false;
        
        for (int& num : arr)
        {
            if (num >= 50 && !(num & 1))
            {
                num /= 2;
                anyChange = true;
            }
            else if (num < 50 && (num & 1))
            {
                num = (2 * num) + 1;
                anyChange = true;
            }
        }
        
        ++answer;
    }
    
    return answer - 1;
}