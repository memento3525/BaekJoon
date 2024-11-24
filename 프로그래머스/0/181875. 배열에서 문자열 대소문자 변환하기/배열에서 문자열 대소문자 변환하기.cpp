#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    
    for (int i = 0; i < strArr.size(); i += 2)
    {
        std::transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), ::tolower);
    }

    for (int i = 1; i < strArr.size(); i += 2)
    {
        std::transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), ::toupper);
    }
    
    return strArr;
}