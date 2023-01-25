using System;

public class Solution {
    public int solution(int number, int limit, int power) {
        
        int[] count = new int[number + 1];
        for (int i = 1; i <= number; i++) 
        {
            for (int j = 1; j <= number / i; j++) 
                count[i * j]++;
        }
        
        int answer = 0;
        for(int k = 1; k <= number; k++)
        {
            int atk = count[k];
            answer += atk > limit ? power : atk;
        }
        return answer;
    }
}