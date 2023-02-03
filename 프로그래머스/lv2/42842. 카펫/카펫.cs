using System;

public class Solution {
    public int[] solution(int brown, int yellow) {
        
        // 노란색의 크기 구하기
        for(int x = 1; x <= yellow; x++)
        {
            if(yellow % x != 0)
                continue;
            
            int y = yellow / x;
            
            if(x < y) 
                continue;
            
            int width = x + 2;
            int height = y + 2;
            if(width * height == brown + yellow)
                return new int[2] {x + 2, y + 2};
        }
        
        return null;
    }
}