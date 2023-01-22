using System;

public class Solution {
    public int solution(int num1, int num2) {
        double a = (num1 / (double)num2);
        int answer = (int)(System.Math.Truncate(a * 1000));
        return answer;
    }
}