#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (char c : my_string)
    {
        if (c > 'Z') // 소문자
            answer += (c - 'a' + 'A');
        else
            answer += (c + 'a' - 'A');
    }
    
    return answer;
}