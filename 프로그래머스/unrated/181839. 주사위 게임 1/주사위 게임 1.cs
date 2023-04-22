using System;

public class Solution {
    public int solution(int a, int b) 
    {
        int oddCount = 0;
        if(a % 2 == 1) ++oddCount;
        if(b % 2 == 1) ++oddCount;
        
        if(oddCount == 2)
            return a * a + b * b;
        else if(oddCount == 1)
            return 2 * (a + b);
        else // oddCount == 0
            return Math.Abs(a - b);
    }
}