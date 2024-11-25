#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int odd = std::count_if(num_list.begin(), num_list.end(), [](int i){ return i & 1; });
    return vector<int>{ (int)num_list.size() - odd, odd };
}