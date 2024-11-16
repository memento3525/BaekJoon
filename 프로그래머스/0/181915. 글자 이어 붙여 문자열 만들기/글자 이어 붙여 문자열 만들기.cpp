#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    
    std::ostringstream os;
    
    for (int i : index_list)
        os << my_string[i];
    
    return os.str();
}