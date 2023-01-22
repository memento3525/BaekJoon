using System;
using System.Text;

public class Solution {
    public string solution(string s) {
        
        var sb = new StringBuilder();
        
        int wordCount = 0;
        for(int i = 0; i < s.Length; i++)
        {
            char c = s[i];
            if(char.IsWhiteSpace(c))
            {
                wordCount = 0;
                sb.Append(" ");
                continue;
            }
            
            sb.Append(wordCount % 2 == 0 ? char.ToUpper(c) : char.ToLower(c)); 
            wordCount++;
        }
        
        return sb.ToString();
    }
}