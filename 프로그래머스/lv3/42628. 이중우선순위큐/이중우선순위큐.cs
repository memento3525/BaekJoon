using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] operations) 
    {
        var dequeue = new Dequeue();
        foreach(string str in operations)
        {
            if(str == "D 1")
            {
                dequeue.DeleteMax();
            }
            else if(str == "D -1")
            {
                dequeue.DeleteMin();
            }
            else
            {
                int n = int.Parse(str.Split()[1]);   
                dequeue.Add(n);
            }
        }
        
        return dequeue.Count > 0 ?  new int[2]{ dequeue.Max, dequeue.Min } : new int[2]{ 0, 0 };
    }
}
    
public class Dequeue
{
    List<int> queue;

    public Dequeue()
    {
        queue = new List<int>();
    }
    
    public int Count => queue.Count;
    public int Max => queue[Count - 1];
    public int Min => queue[0];
    
    public void Add(int n)
    {
        queue.Add(n);
        queue.Sort();
    }
    
    public void DeleteMin()
    {
        if(queue.Count > 0)
            queue.RemoveAt(0);
    }
    
    public void DeleteMax()
    {
        if(queue.Count > 0)
            queue.RemoveAt(queue.Count - 1);
    }
}