using System;

public class Solution {
    public int solution(int a, int b) 
    {
        int left = int.Parse($"{a}{b}");
        int right = 2 * a * b;
        
        return Math.Max(left, right);
    }
}