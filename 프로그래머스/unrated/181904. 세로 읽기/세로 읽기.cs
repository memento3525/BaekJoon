using System;
using System.Text;

public class Solution {
    public string solution(string my_string, int m, int c) 
    {
        var sb = new StringBuilder();
        
        for(int i = 0; i < my_string.Length / m; ++i)
            sb.Append(my_string[i * m + c - 1]);
        
        return sb.ToString();
    }
}