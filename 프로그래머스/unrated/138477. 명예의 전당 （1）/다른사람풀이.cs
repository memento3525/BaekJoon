using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.Length];
        List<int> award = new List<int>();
        int count = 0;
        foreach(int s in score)
        {
            award.Add(s);
            award.Sort();
            if(award.Count>k)
                award.RemoveAt(0);
            answer[count++] = award[0];
        }
        return answer;
    }
}

// 정석적이면서 깔끔한 풀이.
