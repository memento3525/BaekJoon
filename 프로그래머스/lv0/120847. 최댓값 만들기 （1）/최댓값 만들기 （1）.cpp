#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    int length = numbers.size();
    return numbers[length - 1] * numbers[length - 2];
}