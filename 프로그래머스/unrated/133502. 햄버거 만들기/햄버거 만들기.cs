using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] ingredient) {
        
        int answer = 0;
        const int SIZE = 4;
        
        var list = new List<int>();
        for(int i = 0; i < ingredient.Length; i++)
        {
            list.Add(ingredient[i]);
            
            if(list.Count < 4) 
                continue;
            
            if(list[list.Count - 1] == 1 && list[list.Count - 2] == 3
              && list[list.Count - 3] == 2 && list[list.Count - 4] == 1)
            {
                answer++;
                
                for(int k = 0; k < 4; k++)
                    list.RemoveAt(list.Count - 1);
            }
        }
        
        return answer;
    }
}