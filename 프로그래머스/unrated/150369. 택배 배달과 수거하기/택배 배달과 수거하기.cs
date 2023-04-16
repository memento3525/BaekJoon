using System;

public class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) 
    {
        long answer = 0;
        
        int deliverIndex = Array.FindLastIndex(deliveries, (f) => f != 0); // 가장 먼 집부터 배달가야 함.
        int pickupIndex = Array.FindLastIndex(pickups, (f) => f != 0); // 가장 먼 집부터 회수해야 함.
        
        while(deliverIndex >= 0 || pickupIndex >= 0)
        {
            // 가는 길 : 배달 해야하는 가장 먼 지점부터 채워나감
            int deliverDist = 0;
            if(deliverIndex >= 0)
            {
                while(deliverIndex >= 0 && deliveries[deliverIndex] == 0)
                    --deliverIndex;
                
                deliverDist = deliverIndex + 1;
                int curBox = cap; // 현재 담은 용량. 최대치만큼 담음.

                while(curBox > 0 && deliverIndex >= 0)
                {
                    if(deliveries[deliverIndex] == 0)
                    {
                        --deliverIndex;
                        continue;
                    }

                    int landedBox = Math.Min(deliveries[deliverIndex], curBox);
                    deliveries[deliverIndex] -= landedBox;
                    curBox -= landedBox;
                }
            }
            
            // 오는 길 : 역시 가장 먼 지점부터 회수 함
            int pickupDist = 0;
            if(pickupIndex >= 0)
            {
                while(pickupIndex >= 0 && pickups[pickupIndex] == 0)
                    --pickupIndex;
                
                pickupDist = pickupIndex + 1;
                int curEmptyBox = cap; // 최대치만큼 담을 수 있음.

                while(curEmptyBox > 0 && pickupIndex >= 0)
                {
                    if(pickups[pickupIndex] == 0)
                    {
                        --pickupIndex;
                        continue;
                    }

                    int landedBox = Math.Min(pickups[pickupIndex], curEmptyBox);
                    pickups[pickupIndex] -= landedBox;
                    curEmptyBox -= landedBox;
                }
            }
            
            answer += Math.Max(deliverDist, pickupDist); // 가는 거리
        }
        return answer * 2; // 왕복 거리
    }
}