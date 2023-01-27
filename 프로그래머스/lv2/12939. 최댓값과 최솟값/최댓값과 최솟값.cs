using System;

public class Solution {
    public string solution(string s) {
        
        string[] splited = s.Split();
        
        int min = int.MaxValue;
        int max = int.MinValue;
        for(int i = 0; i < splited.Length; i++)
        {
            int n = int.Parse(splited[i]);
            
            if(n > max)
                max = n;
            if(n < min)
                min = n;
        }
        
        return $"{min} {max}";
    }
}