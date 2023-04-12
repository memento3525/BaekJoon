using System;

public class Solution {
    public int solution(string[] board) 
    {
        int count_O = 0;
        int count_X = 0;
        for(int y = 0; y < 3; ++y)
        {
            for(int x = 0; x < 3; ++x)
            {
                char c = board[y][x];
                if(c == 'O') ++count_O;
                if(c == 'X') ++count_X;
            }
        }
        
        if(count_X == 0 && count_O == 0) return 1;
        
        // 후공은 선공보다 많을 수 없다.
        if(count_X - count_O > 0) return 0;
        
        // 선공은 2개이상 많을 수 없다.
        if(count_O - count_X > 1) return 0;
        
        int horizontal_O = 0;
        int horizontal_X = 0;
        int vertical_O = 0;
        int vertical_X = 0;
        
        for(int y = 0; y < 3; ++y) // 가로
        {
            if(board[y] == "OOO")
                ++horizontal_O;
            else if(board[y] == "XXX")
                ++horizontal_X;
        }
        
        for(int y = 0; y < 3; ++y) // 세로
        {
            if(board[y][0] == 'O' && board[y][1] == 'O' && board[y][2] == 'O')
                ++vertical_O;
            else if(board[y][0] == 'X' && board[y][1] == 'X' && board[y][2] == 'X')
                ++vertical_X;
        }
        
        
        if(count_O == count_X)
        {
            // 후공과 갯수가 같은데 선공이 빙고를 1개 만들었다면 오류
            if(horizontal_O >= 1) return 0;
            if(horizontal_X >= 1) return 0;
            if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return 0;
            if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return 0;
        }
        
        // 가로줄 빙고가 2개가 생기면 오류
        if(horizontal_O + horizontal_X >= 2)
            return 0;
        
        // 세로줄 빙고가 2개가 생기면 오류
        if(vertical_O + vertical_X >= 2)
            return 0;
        
        return 1;
    }
}