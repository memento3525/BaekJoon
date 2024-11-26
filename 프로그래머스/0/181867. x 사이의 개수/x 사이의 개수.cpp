#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    stringstream ss(myString);
    string temp;
    char delimiter = 'x';
    
    while (std::getline(ss, temp, delimiter))
    {
        answer.push_back(temp.size());
    }
    
    if (*(myString.end() - 1) == delimiter)
        answer.push_back(0);
    
    return answer;
}