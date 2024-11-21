#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), 
                   [](int n){ 
                       return n * 2; 
                   });
    return numbers;
}