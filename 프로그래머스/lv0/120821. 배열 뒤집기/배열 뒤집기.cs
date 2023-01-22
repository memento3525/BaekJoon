using System;

public class Solution {
    public int[] solution(int[] num_list) {
        
        int[] answer = (int[])num_list.Clone();
        Array.Reverse(answer);
        
        return answer;
    }
}