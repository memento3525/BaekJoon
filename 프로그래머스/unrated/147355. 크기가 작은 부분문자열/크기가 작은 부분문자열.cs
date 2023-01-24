using System;

public class Solution {
    public long solution(string t, string p) {
                
        long answer = 0;
        
        int length = p.Length;
        long pNum = long.Parse(p);
        
        for(int i = 0; i < t.Length - length + 1; i++)
        {
            string str = t.Substring(i, length);
            long num = long.Parse(str);
            
            if(num <= pNum)
                answer++;
        }

        return answer;
    }
}