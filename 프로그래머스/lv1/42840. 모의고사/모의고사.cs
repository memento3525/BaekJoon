using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] answers) {
        
        int[] stu1Array = new int[]{1, 2, 3, 4, 5};
        int[] stu2Array = new int[]{2, 1, 2, 3, 2, 4, 2, 5};
        int[] stu3Array = new int[]{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int[] scores = new int[3];
        scores[0] = answers.Where((e, index) => e == stu1Array[index % stu1Array.Length]).Count();
        scores[1] = answers.Where((e, index) => e == stu2Array[index % stu2Array.Length]).Count();
        scores[2] = answers.Where((e, index) => e == stu3Array[index % stu3Array.Length]).Count();
        
        int maxScore = scores.Max();
        return scores.Select((e, i) => new{val = e, index = i + 1})
                     .Where(e => e.val == maxScore)
                     .Select(e => e.index)
                     .ToArray();
    }
}