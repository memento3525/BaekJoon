using System;
using System.Text;

public class Solution {
    public string solution(string my_string, string overwrite_string, int s) 
    {
        var sb = new StringBuilder();
        
        sb.Append(my_string.Substring(0, s));
        sb.Append(overwrite_string);
        
        int end = s + overwrite_string.Length;
        sb.Append(my_string.Substring(end, my_string.Length - end));
        
        return sb.ToString();
    }
}