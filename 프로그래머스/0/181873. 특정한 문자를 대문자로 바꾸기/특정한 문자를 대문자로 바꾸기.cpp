#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string my_string, string alp) {
    
    string upper(1, toupper(alp[0]));
    while (true)
    {
        size_t pos = my_string.find(alp);
        if (pos == std::string::npos)
            break;
        
        my_string.replace(pos, 1, upper);
    }
    
    return my_string;
}