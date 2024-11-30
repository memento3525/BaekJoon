#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    
    if (my_string.size() < target.size())
        return 0;
    
    return my_string.find(target) != string::npos ? 1 : 0;
}