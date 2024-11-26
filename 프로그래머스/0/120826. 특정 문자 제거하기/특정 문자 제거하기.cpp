#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for (const char& c : my_string)
    {
        if (c != letter[0])
            answer += c;
    }
    
    return answer;
}