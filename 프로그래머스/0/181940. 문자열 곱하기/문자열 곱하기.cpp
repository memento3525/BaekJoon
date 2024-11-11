#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string my_string, int k) {
    
    std::ostringstream oss;
    
    for (int i = 0; i < k; ++i)
        oss << my_string;
    
    return oss.str();
}