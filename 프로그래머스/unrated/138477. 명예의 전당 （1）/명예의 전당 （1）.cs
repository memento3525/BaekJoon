using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int k, int[] score) {
        
        int[] answer = new int[score.Length];
        
        var ranking = new List<int>();
        for(int i = 0; i < score.Length; i++)
        {
            ranking.Add(score[i]);
            
            var enumerator = ranking.OrderByDescending(e => e);
            if(i >= k)
                ranking = enumerator.Take(k).ToList();
            else
                ranking = enumerator.ToList();

            answer[i] = ranking[ranking.Count - 1];
        }
        
        return answer;
    }
}