using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int n) {
        
        // 10진법 -> 3진법 반전 리스트
        List<int> triList = new List<int>();
        int remain = n;
        while(remain > 0)
        {
            triList.Add(remain % 3);
            remain /= 3;
        }
        
        // 3진법 반전리스트 -> 10진법
        int answer = 0;
        for(int i = 0; i < triList.Count; i++)
            answer += (int)Math.Pow(3, triList.Count - i - 1) * triList[i];
        
        return answer;
    }
}