#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    
    stringstream ss(myString);
    string temp;
    char delimiter = 'x';
    
    while (std::getline(ss, temp, delimiter))
    {
        if (!temp.empty())
            answer.push_back(temp);
    }
    
    std::sort(answer.begin(), answer.end());
    
    return answer;
}