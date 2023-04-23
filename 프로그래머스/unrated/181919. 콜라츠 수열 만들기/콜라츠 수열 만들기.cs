using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int n) 
    {
        var list = new List<int>();
        list.Add(n);
        
        while(n != 1)
        {
            if(n % 2 == 0)
                n /= 2;
            else
                n = 3 * n + 1;
            
            list.Add(n);
        }
        return list.ToArray();
    }
}