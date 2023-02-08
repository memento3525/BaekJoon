using System;
using System.Linq;

public class Solution {
    public int solution(int[] citations) {
        
        for(int h = citations.Length; h >= 0; --h)
        {
            int refCount = citations.Count(c => c >= h);
            if(refCount < citations.Length - refCount)
                continue;
            
            if(refCount >= h)
                return h;
        }
        
        return 0;
    }
}