using System;

public class Solution {
    public int[] solution(int[] num_list) {
        
        int odd = 0;
        int even = 0;
        foreach(int item in num_list)
            if(item % 2 == 0) 
                even++;
            else
                odd++;
        
        int[] answer = new int[2] {even, odd};
        return answer;
    }
}