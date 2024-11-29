#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    
    vector<int> answer;
    
    if (direction == "left")
    {
        answer = vector<int>(numbers.begin() + 1, numbers.end());
        answer.push_back(numbers.front());
    }
    else
    {
        answer.push_back(numbers.back());
        answer.insert(answer.end(), numbers.begin(), numbers.end() - 1);
    }
    
    return answer;
}