using System;

public class Solution {
    public int solution(int[] num_list) 
    {
        int answer = 0;
        foreach(int num in num_list)
        {
            int cur = num;
            while(cur != 1)
            {
                if(cur % 2 == 0)
                    cur = cur / 2;
                else
                    cur = (cur - 1) / 2;
                
                ++answer;
            }
        }
        return answer;
    }
}