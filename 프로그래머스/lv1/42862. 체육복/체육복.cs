using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        
        Array.Sort(lost);
        Array.Sort(reserve);
        
        for(int i = 0; i < lost.Length; i++)
        {        
            for(int k = 0; k < reserve.Length; k++)
            {
                if(lost[i] == reserve[k])
                {
                    lost[i] = -1;
                    reserve[k] = -1;
                }
            }
        }
        
        for(int i = 0; i < lost.Length; i++)
        {        
            for(int k = 0; k < reserve.Length; k++)
            {
                if(lost[i] == -1 || reserve[k] == -1) continue;
                if((int)Math.Abs(lost[i] - reserve[k]) == 1)
                {
                    lost[i] = -1;
                    reserve[k] = -1;
                }
            }
        }
        
        return n - lost.Count(c => c != -1);
    }
}