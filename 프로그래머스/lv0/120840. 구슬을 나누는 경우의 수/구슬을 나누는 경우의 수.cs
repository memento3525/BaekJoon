using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public long solution(int balls, int share) {
        if(balls == 1 || balls == share) return 1;

        List<int> children = new List<int>();
        List<int> parents = new List<int>();

        FacAddSet(children, balls);
        FacAddSet(parents, balls - share);
        FacAddSet(parents, share);

        for(int i = 2; i < 50; i++)
        {
            while((children.Contains(i) && parents.Contains(i)))
            {
                children.Remove(i);
                parents.Remove(i);
            }
        }

        foreach(var item in parents)
        {
            Console.WriteLine(item);
        }

        int child = children.Count() == 0 ? 1 : children.Aggregate((n, next) => n * next);
        int parent = parents.Count() == 0 ? 1 : parents.Aggregate((n, next) => n * next);

        return child / (long)parent;
    }

    public void FacAddSet(List<int> list, int n)
    {
        if(n == 0 || n == 1) 
        {
            list.Add(1);
            return;
        }

        for(int i = 2; i <= n; i++)
        {
            List<int> dividers = GetDividers(i);

            if(dividers.Count > 0)
                list.AddRange(dividers);
        }
    }

    public List<int> GetDividers(int n) 
    {
        List<int> dividers = new List<int>();

        int remainedNum = n;
        while(remainedNum > 1)
        {
            for(int i = 2; i <= remainedNum; i++)
            {
                if(remainedNum % i == 0)
                {
                    remainedNum /= i;
                    dividers.Add(i);
                    break;
                }
            }
        }

        return dividers;
    }
}