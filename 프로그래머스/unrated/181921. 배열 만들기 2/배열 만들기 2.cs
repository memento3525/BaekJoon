using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int l, int r) 
    {
        while(l % 5 != 0)
            ++l;
        
        var list = new List<int>();
        for(int i = l; i <= r; i += 5)
        {
            string str = i.ToString().Replace("0", "").Replace("5", "");
            if(string.IsNullOrEmpty(str))
                list.Add(i);
        }
        
        return list.Count == 0 ? new int[1] { -1 } : list.ToArray();
    }
}