using System;

public class Solution {
    public int solution(int[,] board, int k) 
    {
        int answer = 0;
        
        for(int y = 0; y < board.GetLength(0); ++y)
        {
            for(int x = 0; x < board.GetLength(1); ++x)
            {
                if(y + x <= k)
                    answer += board[y, x];
            }
        }
        
        return answer;
    }
}