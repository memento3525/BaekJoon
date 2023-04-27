using System;

public class Solution {
    public int solution(int a, int b, int c) 
    {
        int sameCount = 0;
        if(a == b) ++sameCount;
        if(b == c) ++sameCount;
        if(c == a) ++sameCount;
        
        if(sameCount == 0)
            return a + b + c;
        else if(sameCount == 1)
            return (a + b + c) * (a * a + b * b + c * c);
        else // if(sameCount == 3)
            return (a + b + c) * (a * a + b * b + c * c) *  (a * a * a + b * b * b + c * c * c);
    }
}