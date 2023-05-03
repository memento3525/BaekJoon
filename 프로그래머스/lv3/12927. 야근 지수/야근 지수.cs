using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public long solution(int n, int[] works) 
    {
        Array.Sort(works);
        
        for(int i = 0; i < n; ++i)
        {
            int maxIndex = works.Length - 1; // 맨 뒤에서 부터 탐색
            // 앞의 숫자가 같거나 크다면 index를 앞으로 옮긴다.
            while(maxIndex > 0 && works[maxIndex - 1] >= works[maxIndex])
                --maxIndex;
            
            if(works[maxIndex] == 0) return 0;
            --works[maxIndex];
        }
        
        return works.Select(s => (long)s * s).Sum();
    }
}