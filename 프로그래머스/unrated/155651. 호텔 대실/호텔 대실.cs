using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(string[,] book_time) 
    {
        // 시간을 숫자로 변환한다음 정렬
        var timeList = new List<(int inTime, int outTime)>();
        for(int i = 0; i < book_time.GetLength(0); ++i)
        {
            int inTime = TimeStrToNum(book_time[i, 0]);
            int outTime = TimeStrToNum(book_time[i, 1]);
            timeList.Add((inTime, outTime));
        }
        
        // 정렬된 입실 시간을 하나씩 꺼내면서 방이 비어있으면 넣고, 없으면 만듦
        var sorted = timeList.OrderBy(o => o.Item1);
        var roomList = new List<int>();
        foreach((int inTime, int outTime) t in sorted)
        {
            int room = roomList.FindIndex(f => f <= t.inTime - 10);
            if(room == -1)
                roomList.Add(t.outTime);
            else
                roomList[room] = t.outTime;
        }
        
        return roomList.Count;
    }
    
    private int TimeStrToNum(string str)
    {
        string[] split = str.Split(':');
        return int.Parse(split[0]) * 60 + int.Parse(split[1]);
    }
}