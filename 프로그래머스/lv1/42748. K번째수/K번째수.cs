using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        
        int length = commands.GetLength(0);
        
        int[] answer = new int[length];
        for(int i = 0; i < length; i++)
            answer[i] = Get(array, commands[i, 0], commands[i, 1], commands[i, 2]);
        
        return answer;
    }
    
    private int Get(int[] array, int i, int j, int k)
    {
        var enumerator = array.Skip(i - 1).Take(j - i + 1);
        return enumerator.OrderBy(e => e).ElementAt(k - 1);
    }
}