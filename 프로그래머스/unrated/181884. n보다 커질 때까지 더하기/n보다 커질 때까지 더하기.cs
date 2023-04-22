using System;

public class Solution {
    public int solution(int[] numbers, int n) {
        int answer = 0;
        foreach(int item in numbers)
        {
            answer += item;
            if(answer > n)
                break;
        }
        return answer;
    }
}