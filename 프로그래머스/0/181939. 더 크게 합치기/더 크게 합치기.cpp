#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    
    string str_a = std::to_string(a);
    string str_b = std::to_string(b);
    
    int ab = std::stoi(str_a + str_b);
    int ba = std::stoi(str_b + str_a);
    
    return ab >= ba ? ab : ba;
}