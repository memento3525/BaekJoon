#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    
    for (int i = 0; i < sides.size(); ++i)
    {
        int a = sides[i];
        int b = sides[(i + 1) % sides.size()];
        int c = sides[(i + 2) % sides.size()];
        
        if (a >= b + c)
            return 2;
    }
    
    return 1;
}