#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer = vector<int>(strlist.size());
    transform(strlist.begin(), strlist.end(), answer.begin(), 
              [](string s){ return s.size(); });
    
    return answer;
}