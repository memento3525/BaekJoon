#include <string>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int mult = std::accumulate(num_list.begin(), num_list.end(), 1, std::multiplies<int>());
    int sum = std::accumulate(num_list.begin(), num_list.end(), 0);
    int potSum = std::pow(sum, 2);
    
    return mult < potSum ? 1 : 0;
}