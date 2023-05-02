using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int n, int[,] computers) 
    {
        int answer = 0;
        
        var open = new Stack<int>();
        var close = new HashSet<int>();
        
        for(int i = 0; i < n; ++i)
        {
            if(close.Contains(i)) continue;

            ++answer;
            open.Push(i);
            while(open.Count > 0)
            {
                int popIndex = open.Pop();
                for(int k = 0; k < n; ++k)
                {
                    if(close.Contains(k)) continue;
                    if(computers[popIndex, k] == 1)
                    {
                        close.Add(k);
                        open.Push(k);
                    }
                }
            }
        }
        
        return answer;
    }
}