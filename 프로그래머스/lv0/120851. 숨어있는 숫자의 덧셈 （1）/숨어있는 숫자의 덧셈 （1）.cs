using System;

public class Solution {
    public int solution(string my_string) {
        int answer = 0;
        
        char[] charArray = my_string.ToCharArray();
        
        foreach(char item in charArray)
        {
            if(int.TryParse(item.ToString(), out int num))
                answer += num;
        }
        
        return answer;
    }
}