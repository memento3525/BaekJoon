using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) 
    {
        var stk = new List<int>();
        for(int i = 0; i < arr.Length; ++i)
        {
            if(stk.Count == 0)
                stk.Add(arr[i]);
            else
            {
                if(stk[stk.Count - 1] == arr[i])
                    stk.RemoveAt(stk.Count - 1);
                else
                    stk.Add(arr[i]);
            }
        }
        return stk.Count > 0 ? stk.ToArray() : new int[1]{ -1 };
    }
}