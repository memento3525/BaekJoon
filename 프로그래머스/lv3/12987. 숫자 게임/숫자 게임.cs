using System;
using System.Linq;

public class Solution {
    public int solution(int[] A, int[] B) 
    {
        int answer = 0;
        var listB = B.OrderByDescending(o => o).ToList();
        foreach(int cur in A.OrderByDescending(o => o))
        {
            if(cur >= listB[answer]) continue; // B의 현재 최대값이 이길 수 있을 때 까지 넘김
            ++answer;
        }
        return answer;
    }
}