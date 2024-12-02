#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    stringstream ss(s);
    string temp;
    
    int previous = 0;
    while (ss >> temp)
    {
        if (temp == "Z")
        {
            answer -= previous;
        }
        else
        {
            previous = stoi(temp);
            answer += previous;
        }
    }
    
    return answer;
}