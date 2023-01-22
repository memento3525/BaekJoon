using System;
using System.Text;

public class Solution {
    public string solution(string my_string) {

        var sb = new StringBuilder();
        for(int i = 0; i < my_string.Length; i++)
        {
            char c = my_string[i];
            if(char.IsUpper(c))
                sb.Append(char.ToLower(c));
            else
                sb.Append(char.ToUpper(c));
        }
        
        return sb.ToString();
    }
}