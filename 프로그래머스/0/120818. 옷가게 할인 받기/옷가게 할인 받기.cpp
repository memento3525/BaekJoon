#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    
    if (price < 100000)      return price;
    else if (price < 300000) return price * 0.95f;
    else if (price < 500000) return price * 0.90f;
    else                     return price * 0.80f;
}