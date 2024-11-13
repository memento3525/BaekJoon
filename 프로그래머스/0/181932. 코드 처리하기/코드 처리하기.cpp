#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    
    int mode = 0;
    for (int i = 0; i < code.length(); ++i)
    {
        char c = code[i];
        
        if (c == '1')
        {
            mode = 1 - mode;
            continue;
        }
        
        if (mode == 0 && i % 2 == 0 
            || mode == 1 && i % 2 == 1)
        {
            answer += c;
        }
    }
    
    return answer.length() != 0 ? answer : "EMPTY";
}