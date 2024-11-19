#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for (char i = 'A'; i <= 'Z'; ++i)
    {
        int num = std::count(my_string.begin(), my_string.end(), i);
        answer.push_back(num);
    }    
    for (char i = 'a'; i <= 'z'; ++i)
    {
        int num = std::count(my_string.begin(), my_string.end(), i);
        answer.push_back(num);
    }
    
    return answer;
}