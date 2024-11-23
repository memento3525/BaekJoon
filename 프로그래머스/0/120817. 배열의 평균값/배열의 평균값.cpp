#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> numbers) {
    
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    return sum / (double)numbers.size();
}