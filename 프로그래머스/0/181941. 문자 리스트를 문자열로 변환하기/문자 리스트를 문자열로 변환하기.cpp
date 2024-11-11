#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    
    for (string str : arr)
        answer.append(str);    
    
    return answer;
}