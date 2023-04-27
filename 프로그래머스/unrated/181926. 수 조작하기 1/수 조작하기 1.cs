using System;

public class Solution {
    public int solution(int n, string control) 
    {
        foreach(char c in control)
        {
            if(c == 'w')
                n += 1;
            else if(c == 's')
                n -= 1;
            else if(c == 'd')
                n += 10;
            else if(c == 'a')
                n -= 10;
        }
        return n;
    }
}