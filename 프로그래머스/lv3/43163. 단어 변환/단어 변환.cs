using System;
using System.Linq;

public class Solution {
    public int solution(string begin, string target, string[] words) 
    {
        if(!words.Contains(target)) return 0;
        
        int answer = int.MaxValue;
        bool[] visit = new bool[words.Length];
        DFS(0, begin, target, words, visit, ref answer);
        
        return answer == int.MaxValue ? 0 : answer;
    }
    
    void DFS(int n, string cur, string target, string[] words, bool[] visit, ref int answer)
    {
        if(cur == target)
        {
            if(n < answer)
                answer = n;
            return;
        }
        
        for(int i = 0; i < words.Length; ++i)
        {
            if(visit[i]) continue;
            if(DifferentCount(cur, words[i]) != 1) continue;
            
            visit[i] = true;
            DFS(n + 1, words[i], target, words, visit, ref answer);
            visit[i] = false;
        }
    }
    
    int DifferentCount(string strA, string strB)
    {
        return Enumerable.Range(0, strA.Length).Count(i => strA[i] != strB[i]);
    }
}