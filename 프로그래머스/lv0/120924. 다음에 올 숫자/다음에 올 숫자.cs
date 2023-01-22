using System;

public class Solution {
    public int solution(int[] common) {
        
        // arithmetic : 등차
        // geometric : 등비
        bool isArithmetic = (common[1] - common[0] == common[2] - common[1]);
        
        if(isArithmetic)
        {
            int add = common[1] - common[0];
            return common[common.Length - 1] + add;
        }
        else
        {
            int mult = common[1] / common[0];
            return common[common.Length - 1] * mult;
        }
    }
}