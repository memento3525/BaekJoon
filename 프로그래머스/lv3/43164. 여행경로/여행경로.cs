using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[,] tickets) 
    {
        string[] cur = new string[tickets.GetLength(0) + 1];
        string[] answer = null;
        
        // 시작점을 기준으로 각 티켓을 분류한다. 
        var dict = new Dictionary<string, List<string>>();
        for(int i = 0; i < tickets.GetLength(0); ++i)
        {
            if(!dict.TryGetValue(tickets[i, 0], out var list))
            {
                list = new List<string>();
                dict.Add(tickets[i, 0], list);
            }
            
             list.Add(tickets[i, 1]);
        }
        
        // DFS
        cur[0] = "ICN";
        DFS(1, "ICN", dict, cur, ref answer);
        return answer;
    }
    
    void DFS(int n, string start, Dictionary<string, List<string>> dict, string[] cur, ref string[] answer)
    {
        if(dict.Values.Select(e => e.Count).Sum() == 0)
        {
            if(answer == null)
            {
                answer = (string[])cur.Clone();
                return;
            }
            
            for(int i = 1; i < n; ++i)
            {
                if(cur[i].CompareTo(answer[i]) > 0)
                    break;
                
                if(cur[i].CompareTo(answer[i]) < 0)
                {
                    answer = (string[])cur.Clone();
                    return;
                }
            }
            
            return;
        }
        
        if(!dict.TryGetValue(start, out var list)) return;
        if(list.Count == 0) return;
        
        for(int i = list.Count - 1; i >= 0; --i)
        {
            string end = list[i];
            list.RemoveAt(i);
            cur[n] = end;
            DFS(n + 1, end, dict, cur, ref answer);
            list.Insert(i, end);
        }
    }
}