using System;
using System.Linq;

public class Solution {
    public int[] solution(int num, int total) {
        
        int priorSum = (num * (num + 1)) / 2; // 1 ~ num 까지의 합
        int remainder = (total - priorSum) / num; // 각 자리에 분배해야되는 수
        
        return Enumerable.Range(remainder + 1, num).ToArray();
    }
}