using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[,] clothes) {
        
        var dict = new Dictionary<string, int>();
        for(int i = 0; i < clothes.GetLength(0); i++)
        {
            string typeName = clothes[i, 1];
            if(!dict.ContainsKey(typeName))
                dict[typeName] = 1;
            
            dict[typeName]++;
        }
        
        int answer = 1;
        foreach(var keyPair in dict)
            answer *= keyPair.Value;
        
        return answer - 1;
    }
}