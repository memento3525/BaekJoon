#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {

    if (my_string.size() < is_prefix.size())
        return 0;

    //string sub(my_string.begin(), my_string.begin() + is_prefix.size());
    string sub(my_string, 0, is_prefix.size());
    return sub == is_prefix;
}