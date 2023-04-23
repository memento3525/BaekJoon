using System;
using System.Linq;

public class Solution {
    public int[] solution(string[] intStrs, int k, int s, int l) 
    {
        return intStrs.Select(e => int.Parse(e.Substring(s, l)))
                      .Where(w => w > k).ToArray();
    }
}