using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] id_list, string[] report, int k) {
        int[] answer = new int[] {};
        
        var reportSet = id_list.ToDictionary(e => e, e => new HashSet<string>());
        var reportedSet = id_list.ToDictionary(e => e, e => new HashSet<string>());
        
        for(int i = 0; i < report.Length; i++)
        {
            string[] split = report[i].Split();
            string reporter = split[0];
            string abuser = split[1];
            
            reportSet[reporter].Add(abuser);
            reportedSet[abuser].Add(reporter);
        }
        
        var blockIDs = reportedSet.Where(e => e.Value.Count >= k)
                                  .Select(e => e.Key);
        
        return id_list.Select(id => reportSet[id].Count(q => blockIDs.Contains(q)))
                      .ToArray();
    }
}