using System;
using System.Linq;

public class Solution {
    public string[] solution(string[] strArr) 
    {
        return strArr.Select((c, index) => 
                         {
                             if(index % 2 == 0) return c.ToLower();
                             else return c.ToUpper();
                         }).ToArray();
    }
}