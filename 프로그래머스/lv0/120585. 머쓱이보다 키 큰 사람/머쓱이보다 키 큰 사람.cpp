#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    
    auto find = [&answer, &height](int t){ if(t > height) answer++; };
    for_each(array.begin(), array.end(), find);
    
    return answer;
}