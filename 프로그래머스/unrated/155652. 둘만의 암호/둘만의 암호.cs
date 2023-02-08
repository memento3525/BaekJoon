using System;
using System.Text;
using System.Collections.Generic;

public class Solution {
    public string solution(string s, string skip, int index) {

        var sb = new StringBuilder();
        var list = new List<int>();
        
        for(int i = 'a'; i <= 'z'; i++)
        {
            if(!skip.Contains((char)i))
                list.Add(i);
        }
        
        foreach(char c in s.ToCharArray())
        {
            int num = c;
            int charIndex = list.FindIndex(n => n == num);
            
            num = list[(charIndex + index) % list.Count];
            sb.Append((char)num);
        }
        
        return sb.ToString();
    }
}