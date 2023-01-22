using System;

public class Solution {
    public string[] solution(string[] quiz) {
        
        string[] answer = new string[quiz.Length];
        
        for(int i = 0; i < quiz.Length; i++)
            answer[i] = CalculateStr(quiz[i]);
        
        return answer;
    }
    
    private string CalculateStr(string oneLine)
    {
        string[] splitedStr = oneLine.Split(' ');
        
        int leftResult = 0;
        string lastSign = null;
        foreach(string str in splitedStr)
        {
            if(int.TryParse(str, out int num))
            {
                if(lastSign == null)
                {
                    leftResult = num;
                }
                else if(lastSign == "+")
                {
                    leftResult += num;
                }
                else if(lastSign == "-")
                {
                    leftResult -= num;
                }
                else if(lastSign == "=")
                {
                    return leftResult == num ? "O" : "X";
                }
            }
            else
            {
                lastSign = str;
            }
        }
        
        return "";
    }
}