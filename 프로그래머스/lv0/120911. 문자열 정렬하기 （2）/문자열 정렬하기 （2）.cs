using System;
using System.Linq;

public class Solution {
    public string solution(string my_string) {
        var orderEnumerable = my_string.ToLower().OrderBy(n => n).ToArray();
        return new string(orderEnumerable);
    }
}