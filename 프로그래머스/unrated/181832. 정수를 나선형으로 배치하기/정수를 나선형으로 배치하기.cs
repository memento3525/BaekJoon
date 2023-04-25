using System;

public class Solution {
    public int[,] solution(int n) 
    {
        int[] dir_y = new int[4]{ 0,  1,  0, -1 };
        int[] dir_x = new int[4]{ 1,  0, -1,  0 };
        int dirIndex = 0;
        
        int[,] answer = new int[n, n];
        
        int cur = 1;
        int y = 0;
        int x = 0;
        int maxCount = n;
        int curMoveCount = maxCount;
        int repeat = 1;
        while(cur <= n * n)
        {
            answer[y, x] = cur;
            ++cur;
            
            --curMoveCount;
            if(curMoveCount == 0)
            {
                --repeat;
                if(repeat == 0)
                {
                    --maxCount;
                    repeat = 2;
                }
                
                curMoveCount = maxCount;
                dirIndex = (dirIndex + 1) % 4;
            }
            
            y += dir_y[dirIndex];
            x += dir_x[dirIndex];
        }
        return answer;
    }
}