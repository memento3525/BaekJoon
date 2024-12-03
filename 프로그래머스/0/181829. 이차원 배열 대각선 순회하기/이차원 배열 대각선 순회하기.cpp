#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    
    for (int y = 0; y <= k && y < board.size(); ++y)
    {       
        for (int x = 0; x <= k && x < board[y].size(); ++x)
        {
            if (y + x > k)
                break;
            
            answer += board[y][x];
        }
    }
    
    return answer;
}