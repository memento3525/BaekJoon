#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    
    string answer = "";
    
    for (char& c : myString)
    {
        if (c == 'a' || c == 'A')
            answer += 'A';
        else
            answer += tolower(c);
    }

    return answer;
}