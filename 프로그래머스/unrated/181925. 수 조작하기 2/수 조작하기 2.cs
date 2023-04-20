using System;
using System.Text;

public class Solution {
    public string solution(int[] numLog) 
    {
        var sb = new StringBuilder();
        int n = numLog[0];
        for(int i = 1; i < numLog.Length; ++i)
        {
            int next = numLog[i];
            
            if(n + 1 == next)       sb.Append("w");
            else if(n - 1 == next)  sb.Append("s");
            else if(n + 10 == next) sb.Append("d");
            else if(n - 10 == next) sb.Append("a");
            
            n = next;
        }
        
        return sb.ToString();
    }
}