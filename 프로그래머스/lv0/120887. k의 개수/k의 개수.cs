using System;

public class Solution {
    public int solution(int i, int j, int k) {
        int answer = 0;
        // Convert.ToChar(k)는 아스키 코드에 대한 변환이라서 여기서는 사용 X
        char targetChar = k.ToString()[0]; // char.Parse(k.ToString());
        
        for(int num = i; num < j + 1; num++)
        {
            foreach(char item in num.ToString())
            {
                if(item == targetChar)
                    answer++;
            }
        }
        
        return answer;
    }
}