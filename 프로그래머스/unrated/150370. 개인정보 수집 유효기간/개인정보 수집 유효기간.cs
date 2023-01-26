using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    
    private const int MONTH_DAY = 28;
    
    public int[] solution(string today, string[] terms, string[] privacies) {
        
        // 약관규정 일수로 변환
        var termDayDict = new Dictionary<string, int>();
        for(int i = 0; i < terms.Length; i++)
        {
            string[] split = terms[i].Split();
            int durationNum = int.Parse(split[1]) * MONTH_DAY;
            termDayDict.Add(split[0], durationNum);
        }
        
        // 금일을 일수로 변환
        int todayNum = TimeToNum(today);
        
        // 수집된 약관 체크
        List<int> answerList = new List<int>();
        for(int i = 0; i < privacies.Length; i++)
        {
            string[] split = privacies[i].Split();
            int collectDayNum = TimeToNum(split[0]);
            int temDuration = termDayDict[split[1]];
            
            if(todayNum >= collectDayNum + temDuration)
                answerList.Add(i + 1);
        }
        
        return answerList.ToArray();
    }
    
    private int TimeToNum(string time)
    {
        string[] split = time.Split('.');
        return int.Parse(split[0]) * 12 * MONTH_DAY + int.Parse(split[1]) *MONTH_DAY +  int.Parse(split[2]);
    }
    
    private string NumToTime(int day)
    {
        int d = day % MONTH_DAY;
        int m = day / MONTH_DAY;
        int y = m / 12;
        m %= 12;
        
        return $"{y:0000}.{m:00}.{d:00}";
    }
    
}