#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    while (age != 0)
    {
        int n = age % 10;
        answer = (char)('a' + n) + answer;
        age /= 10;
    }
    
    return answer;
}