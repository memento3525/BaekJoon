using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, bool[] flag) 
    {
        var list = new List<int>();
        
        for(int i = 0; i < flag.Length; ++i)
        {
            int repeat = arr[i];
            if(flag[i])
            {
                for(int k = 0; k < repeat * 2; ++k)
                    list.Add(repeat);
            }
            else
            {
                for(int k = 0; k < repeat; ++k)
                    list.RemoveAt(list.Count - 1);
            }
        }
        
        return list.ToArray();
    }
}