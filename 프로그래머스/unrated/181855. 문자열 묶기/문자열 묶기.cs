using System;
using System.Linq;

public class Solution {
    public int solution(string[] strArr) {
        return strArr.GroupBy(g => g.Length)
                     .OrderByDescending(o => o.Count())
                     .First().Count();
    }
}