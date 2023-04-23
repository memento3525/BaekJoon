using System;

public class Solution {
    public int solution(int[] num_list) 
    {
        string even = "";
        string odd = "";
        
        foreach(int n in num_list)
        {
            if(n % 2 == 0)
                even += n.ToString();
            else
                odd += n.ToString();
        }
        
        return int.Parse(even) + int.Parse(odd);
    }
}