using System;
using System.Linq;

public class Solution {
    public string[] solution(string[] players, string[] callings) 
    {
        var dict = players.Select((s, i) => new{name = s, index = i})
                          .ToDictionary(d => d.name, d => d.index);
        
        foreach(string call in callings)
        {
            int rank = dict[call]; // 추월하려는 사람의 순위
            string overtaken = players[rank - 1]; // 추월당한 사람의 이름
            
            players[rank - 1] = call;
            players[rank] = overtaken;
            
            dict[call] = rank - 1;
            dict[overtaken] = rank;
        }
        
        return players;
    }
}