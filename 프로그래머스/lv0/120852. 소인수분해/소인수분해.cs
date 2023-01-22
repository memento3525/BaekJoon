using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int n) {
        
        List<int> dividers = new List<int>();
        
        int remainedNum = n;
        while(remainedNum > 1)
        {
            for(int i = 2; i <= remainedNum; i++)
            {
                if(remainedNum % i == 0)
                {
                    remainedNum /= i;
                    dividers.Add(i);
                    break;
                }
            }
        }

        return dividers.Distinct().OrderBy(k => k).ToArray();
    }
}