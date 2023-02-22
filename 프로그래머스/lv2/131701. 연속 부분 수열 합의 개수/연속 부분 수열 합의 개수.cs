using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] elements) {
        
        var hashSet = new HashSet<int>();
        for(int c = 0; c < elements.Length; c++) // 더하는 갯수
        {
            for(int k = 0; k < elements.Length; k++) // 시작 지점
            {
                int sum = 0;
                for(int index = 0; index < c; index++)
                    sum += elements[(k + index) % elements.Length];
                
                hashSet.Add(sum);
            }
        }
        
        return hashSet.Count;
        
    }
}