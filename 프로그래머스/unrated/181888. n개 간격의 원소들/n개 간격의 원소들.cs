using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] num_list, int n) 
    {
        var list = new List<int>();
        
        for(int i = 0; i < num_list.Length; i += n)
            list.Add(num_list[i]);
        
        return list.ToArray();
    }
}