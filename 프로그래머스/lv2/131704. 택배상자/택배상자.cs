using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] order) // 택배 기사가 원하는 순서
    {
        int orderIndex = 0; // 택배 기사가 원하는 순서의 배열 인덱스
        var stack = new Stack<int>(); // 보조 벨트
        for(int i = 0; i < order.Length; ++i)
        {
            int box = i + 1; // 메인 벨트에서 나오는 박스에 써진 숫자
            if(box == order[orderIndex])
                ++orderIndex;
            else
                stack.Push(box);
            
            while(stack.Count > 0 && stack.Peek() == order[orderIndex])
            {
                stack.Pop();
                ++orderIndex;
            }
        }
        
        return orderIndex;
    }
}