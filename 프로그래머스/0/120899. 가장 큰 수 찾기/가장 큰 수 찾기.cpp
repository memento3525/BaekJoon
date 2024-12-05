#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    auto it = std::max_element(array.begin(), array.end());
    return vector<int>{ *it, (int)(it - array.begin()) };
}