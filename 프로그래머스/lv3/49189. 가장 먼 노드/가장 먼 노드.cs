using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int n, int[,] edge) 
    {
        bool[,] matrix = new bool[n, n];
        int[] distance = new int[n];
        for(int i = 0; i < edge.GetLength(0); ++i)
        {
            matrix[edge[i, 0] - 1, edge[i, 1] - 1] = true;
            matrix[edge[i, 1] - 1, edge[i, 0] - 1] = true;
        }
        
        var queue = new Queue<int>();
        var visit = new bool[n];
        queue.Enqueue(0);
        visit[0] = true;
        
        while(queue.Count > 0)
        {
            int pop = queue.Dequeue();
            for(int i = 0; i < n; ++i)
            {
                if(visit[i]) continue;
                if(matrix[pop, i])
                {
                    queue.Enqueue(i);
                    visit[i] = true;
                    distance[i] = distance[pop] + 1;
                }
            }
        }
        
        int max = distance.Max();
        return distance.Count(e => e == max);
    }
}