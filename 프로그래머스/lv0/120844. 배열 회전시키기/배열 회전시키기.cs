using System;

public class Solution {
    public int[] solution(int[] numbers, string direction) {
        
        int size = numbers.Length;
        int[] answer = new int[size];
        
        int offset = direction == "left" ? 1 : -1;
        
        for(int i = 0; i < size; i++)
        {
            int offsetIndex = (i + offset + size) % size;
            answer[i] = numbers[offsetIndex];
        }
        
        return answer;
    }
}