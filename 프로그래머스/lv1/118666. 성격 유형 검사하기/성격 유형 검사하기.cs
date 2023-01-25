using System;
using System.Text;

public class Solution {
    
    public const int TYPE_SIZE = 4;
    
    public string solution(string[] survey, int[] choices) {
        
        char[] charArray = {'R', 'C', 'J', 'A', 'T', 'F', 'M', 'N'};
        int[] score = new int[TYPE_SIZE];
        
        for(int i = 0; i < survey.Length; i++)
        {
            for(int k = 0; k < charArray.Length; k++)
            {
                if(survey[i][0] != charArray[k])
                    continue;
                
                if(k < charArray.Length / 2)
                {
                    score[k] += (4 - choices[i]);
                }
                else
                {
                    int index = (k + TYPE_SIZE) % charArray.Length;
                    score[index] -= (4 - choices[i]);
                }
            }
        }
        
        var sb = new StringBuilder();
        for(int i = 0; i < score.Length; i++)
        {
            char targetChar = charArray[i];
            char pairChar = charArray[i + TYPE_SIZE];
            
            if(score[i] == 0)
            {
                sb.Append((int)targetChar < (int)pairChar ? targetChar : pairChar);
                continue;
            }
            
            sb.Append(score[i] > 0 ? targetChar : pairChar);
        }
        
        return sb.ToString();
    }
}