using System;

public class Solution {
    public int solution(int storey) 
    {
        int minValue = int.MaxValue;
        string str = storey.ToString();
        DFS(str, str.Length - 1, 0, 0, ref minValue);
        
        return minValue;
    }
    
    private void DFS(string str, int i, int count, int reversed, ref int minValue)
    {
        if(i == -1) // 탐색 완료
        {
            count += reversed;
            minValue = count < minValue ? count : minValue;
            return;
        }
        
        int num = str[i] - '0' + reversed;
        DFS(str, i - 1, count + num,      0, ref minValue);
        DFS(str, i - 1, count + 10 - num, 1, ref minValue);
    }
}