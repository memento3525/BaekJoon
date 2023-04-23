using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int n, int[] slicer, int[] num_list) 
    {
        int start = 0;
        int end = num_list.Length - 1;
        int term = 1;
        
        if(n == 1) // 0번 인덱스부터 b번 인덱스까지
        {
            end = slicer[1];
        }
        else if(n == 2) // a번 인덱스부터 마지막 인덱스까지
        {
            start = slicer[0];
        }
        else if(n == 3) // a번 인덱스부터 b번 인덱스까지
        {
            start = slicer[0];
            end = slicer[1];
        }
        else // n == 4 // a번 인덱스부터 b번 인덱스까지 c 간격으로
        {
            start = slicer[0];
            end = slicer[1];
            term = slicer[2];
        }
        
        var list = new List<int>();
        for(int i = start; i <= end; i += term)
            list.Add(num_list[i]);
        
        return list.ToArray();
    }
}