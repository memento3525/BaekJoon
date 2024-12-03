#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    
    vector<vector<int>> answer;
    for (int i = 0; i < n; ++i)
        answer.push_back(vector<int>(n, 0));
    
    int y[4] = { 0, 1, 0, -1 };
    int x[4] = { 1, 0, -1, 0 };
    
    int posY = 0;
    int posX = 0;
    int current = 1;
    int dir = -1;
    
    answer[0][0] = 1;
    while (current < n * n)
    {
        dir = (dir + 1) % 4;
        
        while (true)
        {
            int peekY = posY + y[dir];
            int peekX = posX + x[dir];

            if (peekX >= n || peekX < 0) break;
            if (peekY >= n || peekY < 0) break;
            if (answer[peekY][peekX] != 0) break;
            
            posY = peekY;
            posX = peekX;

            answer[posY][posX] = ++current;
        }
    }
    
    return answer;
}