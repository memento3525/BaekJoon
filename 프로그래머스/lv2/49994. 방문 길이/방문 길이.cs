using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string dirs) {
        
        int answer = dirs.Length;
        int x = 0;
        int y = 0;
        var hashSet = new HashSet<string>();
        
        for(int i = 0; i < dirs.Length; i++)
        {
            string startPoint = $"{x}_{y}";
            if(!Move(dirs[i], ref x, ref y))
            {
                answer--;
                continue;
            }
            
            if(hashSet.Contains($"{startPoint}/{x}_{y}") || hashSet.Contains($"{x}_{y}/{startPoint}"))
            {
                answer--;
                continue;
            }
            
            hashSet.Add($"{startPoint}/{x}_{y}");
        }
        
        return answer;
    }
    
    private bool Move(char c, ref int x, ref int y)
    {
        switch(c)
        {
            case 'U': 
                if(y >= 5) return false;
                y++; break;
            case 'D': 
                if(y <= -5) return false;
                y--; break;
            case 'R':  
                if(x >= 5) return false;
                x++; break;
            case 'L': 
                if(x <= -5) return false;
                x--; break;
        }
        return true;
    }
    
}