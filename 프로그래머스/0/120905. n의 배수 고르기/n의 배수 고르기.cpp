#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    for (const int& num : numlist)
    {
        if (num % n == 0)
            answer.emplace_back(num);
    }
    
    return answer;
}