using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public long solution(long n) {
        
        List<long> list = new List<long>();
        
        while(n > 0)
        {
            list.Add(n % 10);
            n /= 10;
        }
        
        return list.OrderByDescending(e => e)
                   .Aggregate((e, next) => e = e * 10 + next);
    }
}