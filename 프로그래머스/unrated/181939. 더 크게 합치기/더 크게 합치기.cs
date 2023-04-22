using System;

public class Solution {
    public int solution(int a, int b) 
    {
        int aNum = Int32.Parse($"{a}{b}");
        int bNum = Int32.Parse($"{b}{a}");
        return Math.Max(aNum, bNum);
    }
}