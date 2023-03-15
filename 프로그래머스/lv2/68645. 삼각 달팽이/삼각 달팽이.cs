using System;

public class Solution 
{
    public int[] solution(int n) 
    {
        int[] dirX = new int[3] { 0, 1, -1 }; // 아래, 오른쪽, 왼쪽위 순
        int[] dirY = new int[3] { 1, 0, -1 };
        
        int[][] snail = new int[n][];
        for(int i = 0; i < n; ++i)
            snail[i] = new int[i + 1];
        
        int x = 0;
        int y = 0;
        int cur = 1;
        int maxMoveCount = n;
        int curMoveCount = maxMoveCount;
        int dirIndex = 0;
        int size = (n * (n + 1))/2; // 등차수열의 합
        while (true)
        {
            if (snail[y][x] != 0)
                break;

            snail[y][x] = cur; // 현재값 넣고 +1
            
            if(cur == size)
                break;
            
            ++cur;
            --curMoveCount;
            if (curMoveCount == 0)
            {
                --maxMoveCount;
                curMoveCount = maxMoveCount;
                dirIndex = (dirIndex + 1) % dirX.Length;
            }

            x += dirX[dirIndex];
            y += dirY[dirIndex];
        }

        int[] answer = new int[size]; // 등차수열의 합
        int index = 0;
        foreach(int[] oneArray in snail)
        {
            foreach(int num in oneArray)
            {
                answer[index] = num;
                ++index;
            }
        }
        
        return answer;
    }
}