#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    
    if (eq == "=" && n != n)  return 0;
    
    if (ineq == "<")
    {
        if (n > m) return 0;
    }
    else // ">" 
    {
        if (n < m) return 0;
    }
      
    return 1;
}