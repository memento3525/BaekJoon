using System;

public class Solution {
    public int[] solution(int[] num_list, int n) // n이 1번부터 시작하는 인덱스임에 주의
    {
        int[] answer = new int[num_list.Length];
        
        Array.Copy(num_list, n, answer, 0, num_list.Length - n); // n 번째이후 원소 -> 앞으로 
        Array.Copy(num_list, 0, answer, num_list.Length - n, n); // n 번째까지의 원소 -> 뒤로
        
        return answer;
    }
}