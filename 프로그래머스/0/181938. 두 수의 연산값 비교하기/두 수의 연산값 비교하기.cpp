#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    
    int appendValue = stoi(to_string(a) + to_string(b));
    int multValue = 2 * a * b; 
    
    return max(appendValue, multValue);
}