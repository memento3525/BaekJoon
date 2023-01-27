using System;
using System.Linq;

public class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        
        int[] orderArray = score.OrderByDescending(e => e).ToArray();
        
        for(int i = 0; i + m - 1 < orderArray.Length; i += m)
        {
            int minPrice = orderArray[i + m - 1];
            answer += minPrice * m;
        }

        return answer;
    }
}