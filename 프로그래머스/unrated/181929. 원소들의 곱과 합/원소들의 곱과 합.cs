using System;
using System.Linq;

public class Solution {
    public int solution(int[] num_list) 
    {
        int a = num_list.Aggregate((cur, next) => cur * next);
        
        int sum = num_list.Sum();
        int b = sum * sum;
        
        return a < b ? 1 : 0;
    }
}