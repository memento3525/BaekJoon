using System;

public class Solution {
    public int[] solution(string[] wallpaper) 
    {
        int minX = int.MaxValue;
        int minY = int.MaxValue;
        int maxX = int.MinValue;
        int maxY = int.MinValue;
        
        for(int y = 0; y < wallpaper.Length; ++y)
        {
            for(int x = 0; x < wallpaper[y].Length; ++x)
            {
                if(wallpaper[y][x] == '#')
                {
                    if(minX > x) minX = x;
                    if(maxX < x) maxX = x;
                    if(minY > y) minY = y;
                    if(maxY < y) maxY = y;
                }
            }
        }
        
        return new int[4]{ minY, minX, maxY + 1, maxX + 1 };
    }
}