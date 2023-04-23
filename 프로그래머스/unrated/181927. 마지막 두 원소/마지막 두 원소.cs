using System;

public class Solution {
    public int[] solution(int[] num_list) 
    {
        int[] answer = new int[num_list.Length + 1];
        Array.Copy(num_list, answer, num_list.Length);
        int a = num_list[num_list.Length - 2];
        int b = num_list[num_list.Length - 1];
        answer[answer.Length - 1] = b > a ? b - a : b * 2;
        return answer;
    }
}