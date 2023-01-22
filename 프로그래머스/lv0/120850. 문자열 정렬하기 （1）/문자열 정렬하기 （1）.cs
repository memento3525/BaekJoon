using System;
using System.Linq;

public class Solution {
    public int[] solution(string my_string) {
        
        return my_string.Where(n => char.IsNumber(n))
                        .Select(n => (int)char.GetNumericValue(n))
                        .OrderBy(n => n)
                        .ToArray();
    }
}