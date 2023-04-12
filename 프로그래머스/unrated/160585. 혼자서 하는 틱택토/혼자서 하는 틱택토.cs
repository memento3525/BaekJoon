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
                if(board[y][x] == 'O') ++count_O;
                else if(board[y][x] == 'X') ++count_X;
            }
        }
        
        // 선공은 2개이상 많을 수 없다.
        if(count_O > count_X + 1) return 0;
        // 후공은 선공보다 많을 수 없다.
        if(count_X > count_O) return 0;
        
        int bingo_O = 0;
        int bingo_X = 0;
        
        for(int y = 0; y < 3; ++y) // 가로
        {
            if(board[y] == "OOO") ++bingo_O;
            else if(board[y] == "XXX") ++bingo_X;
        }
        
        for(int y = 0; y < 3; ++y) // 세로
        {
            if(board[0][y] == 'O' && board[1][y] == 'O' && board[2][y] == 'O') ++bingo_O;
            else if(board[0][y] == 'X' && board[1][y] == 'X' && board[2][y] == 'X') ++bingo_X;
        }
        
        // 대각선
        if(board[1][1] == 'O')
        {
            if((board[0][0] == 'O' && board[2][2] == 'O')) ++bingo_O;
            if((board[0][2] == 'O' && board[2][0] == 'O')) ++bingo_O;
        }
        else if(board[1][1] == 'X')
        {
            if((board[0][0] == 'X' && board[2][2] == 'X')) ++bingo_X;
            if((board[0][2] == 'X' && board[2][0] == 'X')) ++bingo_X;
        }
        
        // 둘 다 빙고를 만들 수 없다.
        if(bingo_O > 0 && bingo_X > 0) return 0;
        
        // 선공이 이겼는데 표식 갯수가 같으면 오류
        if(bingo_O > bingo_X && count_O == count_X) return 0;
        
        // 후공이 이겼는데 선공이 한번 더 진행했다면 오류
        if(bingo_X > bingo_O && count_O > count_X) return 0;
        
        return 1;
    }
}