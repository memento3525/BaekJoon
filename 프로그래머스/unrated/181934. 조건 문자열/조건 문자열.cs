using System;

public class Solution {
    public int solution(string ineq, string eq, int n, int m) 
    {
        if(ineq == ">")
        {
            if(n < m) return 0;
        }
        else
        {
            if(n > m) return 0;
        }
        
        if(eq == "!")
        {
            if(n == m) return 0;
        }
        
        return 1;
    }
}