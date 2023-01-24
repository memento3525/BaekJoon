using System;
using System.Linq;

public class Solution {
    public int solution(string s) {
        
        int splitCount = 0;
        
        char? x = null;
        int sameCount = 0;
        int otherCount = 0;
        for(int i = 0; i < s.Length; i++)
        {
            if(!x.HasValue)
                x = s[i];
            
            if(x == s[i])
                sameCount++;
            else
                otherCount++;
            
            if(sameCount == otherCount)
            {
                splitCount++;
                x = null;
                sameCount = 0;
                otherCount = 0;
            }
        }
        
        if(sameCount > 0 || otherCount > 0)
            splitCount++;
        
        return splitCount;
    }
}