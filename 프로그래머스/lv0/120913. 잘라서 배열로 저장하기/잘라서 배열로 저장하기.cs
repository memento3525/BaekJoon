using System;

public class Solution {
    public string[] solution(string my_str, int n) 
    {
        int size = my_str.Length / n;
        if(my_str.Length % n != 0)
           size++;
        
        string[] answer = new string[size];
        
        for(int i = 0; i < size; i++)
        {
            int startIndex = i * n;
            int length = Math.Min(n, my_str.Length - startIndex);
            
            answer[i] = my_str.Substring(startIndex, length);
        }
        
        return answer;
    }
}