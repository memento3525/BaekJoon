using System;
using System.Linq;

public class Solution {
    public string solution(string my_string, int[] indices) 
    {
        return new string(my_string.Where((w, index) => !indices.Contains(index)).ToArray());
    }
}