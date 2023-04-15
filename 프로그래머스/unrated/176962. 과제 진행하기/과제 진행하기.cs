using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public class Test
    {
        public string name;
        public int start;
        public int remain;
        
        public Test(string name, string timeStr, string playTimeStr)
        {
            this.name = name;
            string[] splited = timeStr.Split(':');
            start = int.Parse(splited[0]) * 60 + int.Parse(splited[1]);
            remain = int.Parse(playTimeStr);
        }
    }
    
    public string[] solution(string[,] plans) 
    {
        var answer = new List<string>();
        var willPlayed = new Test[plans.GetLength(0)];
        var holded = new Stack<Test>();
        
        for(int i = 0; i < plans.GetLength(0); ++i)
            willPlayed[i] = new Test(plans[i, 0], plans[i, 1], plans[i, 2]);
        
        Array.Sort(willPlayed, (a, b) => a.start < b.start ? -1 : 1);
        
        int time = 0;
        int startIndex = 0;
        while(startIndex < plans.GetLength(0))
        {
            Test cur = willPlayed[startIndex];
            time = cur.start;
            
            bool isLast = startIndex + 1 == plans.GetLength(0);
            int availableTime = isLast ? int.MaxValue : willPlayed[startIndex + 1].start - time;
            
            holded.Push(cur);
            while(holded.Count > 0)
            {
                Test top = holded.Peek();
                if(availableTime >= top.remain) // 시간 충분. 꺼낸 과제완료
                {
                    time += top.remain;
                    availableTime -= top.remain;
                    answer.Add(top.name);
                    holded.Pop();
                    
                    if(availableTime == 0)
                        break;
                }
                else // 꺼낸 과제를 완료하기에는 시간이 부족함.
                {
                    time += availableTime;
                    top.remain -= availableTime;
                    break;
                }
            }
                
            ++startIndex;
        }
        
        return answer.ToArray();
    }
}