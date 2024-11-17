#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    
    if (my_string.size() < is_suffix.size())
        return 0;
    
    int length = is_suffix.size();
    string substr = my_string.substr(my_string.size() - length, length);
    return substr == is_suffix;
}