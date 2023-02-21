using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] priorities, int location) {
        
        int answer = 1;
        var queue = new Queue<(int, int)>(priorities.Select((s, index) => (s, index)).ToArray()); 
        
        while(queue.Count() > 0)
        {
            (int priority, int index) current = queue.Dequeue();
            
            bool isAnyImportant = false;
            foreach((int priority, int index) other in queue)
            {
                if(current.priority < other.priority)
                {
                    queue.Enqueue(current);
                    isAnyImportant = true;
                    break;
                }
            }
            
            if(isAnyImportant)
                continue;
            
            // 프린트
            if(location == current.index)
                return answer;

            answer++;
        }
        
        return answer;
    }
}