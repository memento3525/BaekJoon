using System;
using System.Text;

public class Solution {
    public string solution(string my_string, int n) {
        
        char[] charArray = my_string.ToCharArray();
        
        StringBuilder sb = new StringBuilder();
        foreach(char item in charArray)
        {
            for(int i = 0; i < n; i++)
                sb.Append(item);
        }
        
        return sb.ToString();
    }
}