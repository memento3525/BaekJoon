using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(string[] want, int[] number, string[] discount) {
        
        const int MEMBER_DAY = 10;
        Dictionary<string, int> dict =  want.Select((value, index) => new { value, index })
                                            .ToDictionary(pair => pair.value, pair => number[pair.index]);
            
        int answer = 0;
        
        for(int i = 0 ; i < discount.Length - MEMBER_DAY + 1; i++)
        {
            if(IsCanBuy(dict, discount, i, MEMBER_DAY))
                answer++;
        }
        
        return answer;
    }
    
    private bool IsCanBuy(Dictionary<string, int> dict, string[] discount, int start, int length)
    {
        List<string> remained = discount.Skip(start).Take(length).ToList();
        foreach(var pair in dict)
        {
            if(remained.Count == 0)
                return false;
                
            for(int i = 0; i < pair.Value; i++) // 횟수반복
            {
                if(!remained.Remove(pair.Key))
                    return false;
            }
        }
        
        return true;
    }
}