using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] genres, int[] plays) 
    {
        var zipList = Enumerable.Range(0, genres.Length)
                                .Select(s => new{ index = s, genre = genres[s], play = plays[s]})
                                .ToList();
        
        List<string> genreRank = zipList.GroupBy(g => g.genre)
                                        .Select(s => new{ genre = s.Key, sum = s.Sum(t => t.play)} )
                                        .OrderByDescending(o => o.sum)
                                        .Select(s => s.genre)
                                        .ToList();
        
        var topTwoEnumerable = zipList.GroupBy(g => g.genre)
                            .OrderBy(o => genreRank.IndexOf(o.Key))
                            .Select(s => s.OrderByDescending(t => t.play).Take(2));
            
        var list = new List<int>();
        foreach(var x in topTwoEnumerable)
        {
            foreach(var member in x)
                list.Add(member.index);
        }
        
        return list.ToArray();
    }
}