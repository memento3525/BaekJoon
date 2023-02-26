using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] fees, string[] records) {
        
        int baseMinute = fees[0];
        int baseFee = fees[1];
        int minute = fees[2];
        int minuteFee = fees[3];
        int closeTime = StrToMinute("23:59");
        
        // 출입 기록 체크
        var dict = new Dictionary<string, (int inTime, int allDuration)>();
        for(int i = 0; i < records.Length; i++)
        {
            string[] strArray = records[i].Split();
            int time = StrToMinute(strArray[0]);
            string car = strArray[1];
            
            if(strArray[2] == "IN")
            {
                if(!dict.ContainsKey(car))
                    dict[car] = (-1, 0);
                
                (int inTime, int allDuration) tuple = dict[car];
                tuple.inTime = time;
                dict[car] = tuple;
            }
            else if(strArray[2] == "OUT")
            {
                (int inTime, int allDuration) tuple = dict[car];
                int duration = time - tuple.inTime;
                tuple.inTime = -1;
                tuple.allDuration += duration;
                dict[car] = tuple;
            }
        }
        
        // 마감시간 출차
        foreach(var key in dict.Keys.ToArray())
        {
            (int inTime, int allDuration) tuple = dict[key];
            if(tuple.inTime == -1) 
                continue;
            
            int duration = closeTime - tuple.inTime;
            tuple.allDuration += duration;
            dict[key] = tuple;
        }
        
        
        // 요금계산
        int[] answer = new int[dict.Count];
        
        int index = 0;
        foreach(var item in dict.Keys.OrderBy(o => o))
        {
            int remain = dict[item].allDuration;
            
            answer[index] += baseFee;
            if(remain > baseMinute)
            {
                remain -= baseMinute;
                int repeatTime = (remain / minute) + ((remain % minute) != 0 ? 1 : 0);
                answer[index] += repeatTime * minuteFee;
            }
            
            index++;
        }
        
        return answer;
    }
    
    private int StrToMinute(string str)
    {
        string[] strArray = str.Split(':');
        return int.Parse(strArray[0]) * 60 + int.Parse(strArray[1]);
    }
    
}