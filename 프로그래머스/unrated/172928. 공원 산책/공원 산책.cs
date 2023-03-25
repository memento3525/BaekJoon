using System;

public class Solution {
    public int[] solution(string[] park, string[] routes) 
    {
        int y = 0;
        int x = 0;
        
        // 시작지점 찾기
        foreach(string p in park)
        {
            int index = p.IndexOf('S');
            if(index != -1)
            {
                x = index;
                break;
            }
            ++y;
        }
        
        // 길찾기
        foreach(string route in routes)
        {
            string[] splited = route.Split();
            string dir = splited[0];
            int repeat = Convert.ToInt32(splited[1]);
            
            bool isSuccess = true;
            int moveToY = y;
            int moveToX = x;
            for(int i = 0; i < repeat; ++i)
            {
                if(dir == "N") --moveToY;
                else if(dir == "S") ++moveToY;
                else if(dir == "W") --moveToX;
                else ++moveToX; // "E"
                
                if(!IsValidPoint(park, moveToY, moveToX))
                {
                    isSuccess = false;
                    break;
                }
            }
            
            if(isSuccess)
            {
                y = moveToY;
                x = moveToX;
            }
        }
        
        return new int[2] { y, x };
    }
    
    private bool IsValidPoint(string[] park, int y, int x)
    {
        int height = park.Length;
        int width = park[0].Length;
        
        if(y < 0 || y >= height) return false;
        if(x < 0 || x >= width) return false;
        if(park[y][x] == 'X') return false;
        return true;
    }
}