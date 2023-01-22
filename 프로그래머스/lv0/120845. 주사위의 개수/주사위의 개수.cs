using System;

public class Solution {
    public int solution(int[] box, int n) {
        
        int answer = 1;
        
        for(int i = 0; i < box.Length; i++)
        {
            int count = box[i] / n;
            answer *= count;
        }
        
        return answer;
    }
}