using System;
using System.Text;

public class Solution {
    public string solution(string[] arr) {
        var sb = new StringBuilder();
        
        foreach(var c in arr)
            sb.Append(c);
                      
        return sb.ToString();
    }
}