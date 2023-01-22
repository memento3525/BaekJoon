using System;

public class Solution {
    public int solution(string my_string) {
        int answer = 0;
        string[] splitedStr = my_string.Split(' ');
        
        string sign = string.Empty;
        foreach(string item in splitedStr)
        {
            if(int.TryParse(item, out int num))
            {
                if(sign == string.Empty)
                    answer = num;
                else if(sign == "+")
                    answer += num;
                else if(sign == "-")
                    answer -= num;
                
                sign = string.Empty;
            }
            else
            {
                sign = item;
            }
        }
        
        return answer;
    }
}