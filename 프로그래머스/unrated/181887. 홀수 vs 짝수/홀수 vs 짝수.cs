using System;

public class Solution {
    public int solution(int[] num_list) {
        
        int even = 0;
        for(int i = 0; i < num_list.Length; i += 2)
            even += num_list[i];
        
        int odd = 0;
        for(int i = 1; i < num_list.Length; i += 2)
            odd += num_list[i];
        
        return Math.Max(even, odd);
    }
}