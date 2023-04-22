using System;
using System.Linq;

public class Solution {
    public int solution(int[] num_list) 
    {
        if(num_list.Length >= 11)
            return num_list.Sum();
        else
            return num_list.Aggregate((cur, next) => cur * next);
    }
}