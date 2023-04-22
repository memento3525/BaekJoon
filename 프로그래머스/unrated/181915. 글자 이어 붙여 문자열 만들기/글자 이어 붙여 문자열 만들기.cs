using System;
using System.Text;

public class Solution {
    public string solution(string my_string, int[] index_list) 
    {
        var sb = new StringBuilder();
        
        foreach(int n in index_list)
            sb.Append(my_string[n]);
        
        return sb.ToString();
    }
}