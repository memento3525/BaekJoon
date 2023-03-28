using System;
using System.Collections.Generic;

public class Solution {
    public int[,] solution(int n) 
    {
        var list = new List<(int, int)>();
        
        Hanoi(list, n, 1, 3, 2);
        
        int[,] answer = new int[list.Count, 2];
        for(int i = 0; i < list.Count; ++i)
        {
            answer[i, 0] = list[i].Item1;
            answer[i, 1] = list[i].Item2;
        }
        
        return answer;
    }
    
    private void Hanoi(List<(int, int)> list, int n, int start, int end, int sub)
    {
        if(n == 1) 
        {
            Move(list, start, end);
            return;
        }
        
        Hanoi(list, n - 1, start, sub, end); // 맨 밑판 빼고 sub로 이동한다.
        Move(list, start, end); // 맨 밑판을 타겟지점으로 옮긴다.
        Hanoi(list, n - 1, sub, end, start); // 처음에 옮겼던걸 이제 다시 타겟지점으로 옮긴다.
    }
    
    private void Move(List<(int, int)> list, int start, int end)
    {
        list.Add((start, end));
    }
}