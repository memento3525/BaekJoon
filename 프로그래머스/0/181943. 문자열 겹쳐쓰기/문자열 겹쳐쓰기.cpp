#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    std::ostringstream oss;
    
    int i = 0;
    for (; i < s; ++i)
        oss << my_string[i];
    
    oss << overwrite_string;
    i += overwrite_string.length();
    
    for (; i < my_string.length(); ++i)
        oss << my_string[i];
        
    return oss.str();
}