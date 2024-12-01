#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    return std::find(num_list.begin(), num_list.end(), n) != num_list.end();
}