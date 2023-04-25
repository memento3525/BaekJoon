using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) 
    {
        var stk = new List<int>();
        
        for(int i = 0; i < arr.Length;)
        {
            if(stk.Count == 0)
            {
                stk.Add(arr[i]);
                ++i;
            }
            else
            {
                if(stk[stk.Count - 1] < arr[i])
                {
                    stk.Add(arr[i]);
                    ++i;
                }
                else
                {
                    stk.RemoveAt(stk.Count - 1);
                }
            }
        }
        
        return stk.ToArray();
    }
}