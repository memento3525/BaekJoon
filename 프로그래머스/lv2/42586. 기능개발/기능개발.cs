using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        var answer = new List<int>();
        int curIndex = 0;
        
        while(curIndex < progresses.Count())
        {
            for(int i = 0; i < progresses.Count(); i++)
            {
                if(progresses[i] < 100)
                    progresses[i] += speeds[i];
            }
            
            int build = 0;
            while(curIndex < progresses.Count() && progresses[curIndex] >= 100)
            {
                build++;
                curIndex++;
            }
            if(build > 0)
                answer.Add(build);
        }
        
        return answer.ToArray();
    }
}