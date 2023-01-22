using System;

public class Solution {
    public int solution(int[] array) {
        int answer = 0;
        
        int maxValue = -1;
        int maxCount = 0;
        for(int i = 0; i < array.Length; i++)
        {
            if(maxValue == array[i]) continue;
            int count = 0;
            
            for(int k = 0; k< array.Length; k++)
            {
                if(array[i] == array[k])
                    count++;
            }
            
            if(count == maxCount)
            {
                maxValue = -1;
            }
            else if(count > maxCount)
            {
                maxValue = array[i];
                maxCount = count;
            }
        }
        
        return maxValue;
    }
}