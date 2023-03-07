using System;

public class Solution {
    public int solution(int n, int m, int[] section) 
    {
        int answer = 0;
        int index = 0;
        while(index < section.Length)
        {
            int left = section[index];
            while(index < section.Length && section[index] < left + m)
                ++index;
            
            ++answer;
        }
        
        return answer;
    }
}