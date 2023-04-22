using System;
using System.Text;

public class Solution {
    public string solution(string[] my_strings, int[,] parts) 
    {
        var sb = new StringBuilder();
        for(int i = 0; i < parts.GetLength(0); ++i)
        {
            int start = parts[i, 0];
            int end = parts[i, 1];
            
            string subString = my_strings[i].Substring(start, end - start + 1);
            sb.Append(subString);
        }
        return sb.ToString();
    }
}