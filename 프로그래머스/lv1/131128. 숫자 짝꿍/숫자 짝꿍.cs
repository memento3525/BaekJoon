using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public string solution(string X, string Y) {
        
        if(X.Intersect(Y).Count() == 0)
            return "-1";
        
        var groupX = X.GroupBy(e => e).ToDictionary(g => g.Key, g => g.Count());
        var groupY = Y.GroupBy(e => e).ToDictionary(g => g.Key, g => g.Count());
        
        var result = new List<char>();
        foreach(var item in groupX)
        {
            if(!groupY.TryGetValue(item.Key, out int otherValue))
                continue;
            
            int count = (int)Math.Min(item.Value, otherValue);
            
            for(int i = 0; i < count; i++)
                result.Add(item.Key);
        }
            
        result = result.OrderByDescending(e => e).ToList();
        
        while(result.Count() > 1 && result[0] == '0')
            result.RemoveAt(0);
        
        return string.Concat(result);
    }
}