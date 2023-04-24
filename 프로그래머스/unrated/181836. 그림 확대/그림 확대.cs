using System;
using System.Text;

public class Solution {
    public string[] solution(string[] picture, int k) 
    {
        var answer = new string[picture.Length * k];
        
        var sb = new StringBuilder();
        for(int i = 0; i < picture.Length; ++i)
        {
            foreach(char c in picture[i])
            {
                for(int r = 0; r < k; ++r)
                    sb.Append(c);
            }
            
            for(int r = 0; r < k; ++r)
                answer[k * i + r] = sb.ToString();
            
            sb.Clear();
        }
        
        return answer;
    }
}