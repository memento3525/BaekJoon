using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] numbers) {
        
        var hashSet = new HashSet<int>();
        for(int i = 0; i < numbers.Length; i++)
        {
            for(int k = 0; k < numbers.Length; k++)
            {
                if(i == k) continue;
                hashSet.Add(numbers[i] + numbers[k]);
            }
        }
        
        return hashSet.OrderBy(e => e).ToArray();
    }
}