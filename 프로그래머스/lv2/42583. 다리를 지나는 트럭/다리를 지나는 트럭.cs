using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int bridgeLength, int weight, int[] trucks) 
    {
        int time = 0;
        int truckIndex = 0;
        int sum = 0; // 현재 올라간 트럭의 총 무게
        var queue = new Queue<int>(Enumerable.Repeat(0, bridgeLength));
        
        while(!(truckIndex == trucks.Length && sum == 0))
        {
            sum -= queue.Dequeue();
            
            int newItem = 0;
            if(truckIndex < trucks.Length) // 진입해야되는 트럭 남아있다면 
            {
                int next = trucks[truckIndex];
                if(sum + next <= weight)
                {
                    newItem = next;
                    sum += next;
                    ++truckIndex;
                }
            }
            
            queue.Enqueue(newItem);
            ++time;
        }
        
        return time;
    }
}