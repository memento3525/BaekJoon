using System;

public class Solution {
    public int[] solution(string[] keyinput, int[] board) {
        
        int x = 0;
        int y = 0;

        int maxX = board[0] / 2;   
        int maxY = board[1] / 2;        
        
        foreach(string input in keyinput)
        {
            int[] addPos = ConvertMove(input);
            
            x = (int)Math.Clamp(x + addPos[0], -maxX, maxX);
            y = (int)Math.Clamp(y + addPos[1], -maxY, maxY);
        }

        return new int[2] {x, y};
    }
    
    private int[] ConvertMove(string input)
    {
        switch(input)
        {
            case "left": 
                return new int[2]{ -1, 0 };
            case "right": 
                return new int[2]{ 1, 0 };
            case "up": 
                return new int[2]{ 0, 1 };
            case "down": 
                return new int[2]{ 0, -1 };
            default: 
                return new int[2]{ 0, 0 };
        }
    }
    
}