using System;
using System.Linq;

public class Solution {
    
    bool[,] map;
    int length;
    
    public int solution(int[,] board) {
        
        length = board.GetLength(0);
        map = new bool[length, length];
        
        for(int x = 0; x < length; x++)
        {
            for(int y = 0; y < length; y++)
            {
                if(board[x, y] == 1)
                    MarkPoint(x, y);
            }
        }
        
        int answer = 0;
        foreach(bool isDanger in map)
        {
            if(!isDanger)
                answer++;
        }
        
        return answer;
    }
    
    public void MarkPoint(int x, int y)
    {
        for(int i = -1; i < 2; i++)
        {
            for(int k = -1; k < 2; k++)
            {
                int target_x = x + i;
                if(target_x < 0 || target_x >= length)
                    continue;
                    
                int target_y = y + k;
                if(target_y < 0 || target_y >= length)
                    continue;
                
                map[target_x, target_y] = true;
            }
        }
    }
}