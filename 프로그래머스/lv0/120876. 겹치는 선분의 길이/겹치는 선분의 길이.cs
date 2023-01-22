using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[,] lines) {
        Dictionary<string, int> dict = new Dictionary<string, int>();
        
        for(int i = 0; i < lines.GetLength(0); i++)
        {                
            int start = lines[i, 0];
            int end = lines[i, 1];
            for(int k = start; k < end; k++)
            {
                string key = $"{k}-{k+1}";
                if(!dict.ContainsKey(key))
                    dict.Add(key, 0);
                
                dict[key] += 1;
            }
        }
        
        return dict.Count(n => n.Value > 1);
    }
}