#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string str1, string str2) {
    
    std::ostringstream oss;
    
    for (int i = 0; i < str1.length(); ++i)
        oss << str1[i] << str2[i];
    
    return oss.str();
}