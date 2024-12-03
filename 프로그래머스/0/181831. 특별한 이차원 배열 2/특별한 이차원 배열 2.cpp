#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    
    for (int y = 0; y < arr.size(); ++y)
    {
        for (int x = 0; x < y; ++x)
        {
            if (arr[y][x] != arr[x][y])
                return 0;
        }
    }
    
    return 1;
}