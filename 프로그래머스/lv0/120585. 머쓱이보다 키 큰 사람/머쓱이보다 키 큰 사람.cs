using System;

public class Solution {
    public int solution(int[] array, int height) {
        int answer = 0;
        
        foreach(int tall in array)
            if(tall > height) answer++;
        
        return answer;
    }
}