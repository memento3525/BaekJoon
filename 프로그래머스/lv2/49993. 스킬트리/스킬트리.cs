using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string skill, string[] skill_trees) {
        
        int answer = 0;
        foreach(var tree in skill_trees)
        {
            if(IsCanLearn(tree, new Queue<char>(skill)))
                answer++;
        }
        
        return answer;
    }
    
    private bool IsCanLearn(string tree, Queue<char> queue)
    {
        for(int i = 0; i < tree.Length; i++)
        {
            char c = tree[i];
            if(!queue.Contains(c))
                continue;

            if(queue.Peek() == c)
            {
                queue.Dequeue();
                continue;
            }
            
            return false;
        }
        
        return true;
    }
}