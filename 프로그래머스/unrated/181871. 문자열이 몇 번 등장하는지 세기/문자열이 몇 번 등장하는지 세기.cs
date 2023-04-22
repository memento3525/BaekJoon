using System;

public class Solution {
    public int solution(string myString, string pat) 
    {
        int answer = 0;
        int lastIndex = 0;
        
        while(true)
        {
            lastIndex = myString.IndexOf(pat, lastIndex);
            if(lastIndex == -1)
                break;
            
            ++lastIndex;
            ++answer;
        }
        
        return answer;
    }
}