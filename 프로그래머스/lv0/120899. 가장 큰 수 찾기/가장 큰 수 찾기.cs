using System;

public class Solution {
    public int[] solution(int[] array) {
        
        int max = -1;
        int index = 0;
        
        for(int i = 0; i < array.Length; i++)
        {
            if(array[i] > max)
            {
                max = array[i];
                index = i;
            }
        }
        
        return new int[] {max, index};
    }
}