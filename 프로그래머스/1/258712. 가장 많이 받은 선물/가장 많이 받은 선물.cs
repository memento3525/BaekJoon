using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(string[] friends, string[] gifts) 
    {
        int[,] matrix = new int[friends.Length, friends.Length];
        int[] giftPoint = new int[friends.Length];
        for(int i = 0; i < gifts.Length; ++i)
        {
            var splited = gifts[i].Split();
            var senderIndex = Array.IndexOf(friends, splited[0]);
            var receiverIndex = Array.IndexOf(friends, splited[1]);
            
            matrix[senderIndex, receiverIndex]++;
            giftPoint[senderIndex]++;
            giftPoint[receiverIndex]--;
        }
        
        int answer = 0;
        int[] nextMonthReceive = new int[friends.Length];
        for (int a = 0; a < matrix.GetLength(0); ++a)
        {
            for (int b = a + 1; b < matrix.GetLength(1); ++b)
            {
                if (matrix[a, b] > matrix[b, a])
                {
                    nextMonthReceive[a]++;
                }
                else if (matrix[a, b] < matrix[b, a])
                {
                    nextMonthReceive[b]++;
                }
                else // Same
                {
                    if (giftPoint[a] > giftPoint[b])
                    {
                        nextMonthReceive[a]++;
                    }
                    else if (giftPoint[a] < giftPoint[b])
                    {
                        nextMonthReceive[b]++;
                    }
                }
            }
            
            answer = nextMonthReceive[a] > answer ? nextMonthReceive[a] : answer;
        }
        
        return answer;
    }
}