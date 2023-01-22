using System;

public class Solution {
    
    private int[,] dots;
    
    public int solution(int[,] dots) {

        this.dots = dots;
        
        // (AB, CD)
        if(GetSlope(0, 1) == GetSlope(2, 3))
            return 1;
        
        // (AC, BD)
        if(GetSlope(0, 2) == GetSlope(1, 3))
            return 1;
        
        // (AD, BC)
        if(GetSlope(0, 3) == GetSlope(1, 2))
            return 1;
        
        return 0;
    }
    
    public float GetSlope(int indexA, int indexB) {
        float deltaX = (dots[indexA, 0] - dots[indexB, 0]);
        float deltaY = (dots[indexA, 1] - dots[indexB, 1]);
        return deltaY / deltaX;
    }
    
}