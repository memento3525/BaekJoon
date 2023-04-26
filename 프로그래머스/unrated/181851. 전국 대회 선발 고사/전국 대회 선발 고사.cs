using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] rank, bool[] attendance) 
    {
        var list = new List<(int rank, int index)>();
        for(int i = 0; i < rank.Length; ++i)
        { 
            if(!attendance[i]) continue;
            list.Add((rank[i], i));
        }
        
        var arr = list.OrderBy(o => o.Item1).Take(3).ToArray();
        return 10000 * arr[0].Item2 + 100 * arr[1].Item2 + arr[2].Item2;
    }
}