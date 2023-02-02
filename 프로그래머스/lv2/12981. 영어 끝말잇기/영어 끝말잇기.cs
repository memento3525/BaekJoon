using System;
using System.Collections.Generic;

class Solution
{
    public int[] solution(int n, string[] words)
    {
        var hashSet = new HashSet<string>();
        char lastTailChar = default(char);
        
        int player = -1;
        int turn = 0;
        
        try
        {
            for(; turn < words.Length; turn++)
            {
                string w = words[turn];
                player = (turn % n) + 1;
                System.Console.WriteLine($"플레이어{player} : {w}");

                if(string.IsNullOrWhiteSpace(w) || w.Length == 1)
                    throw new Exception($"유효하지 않은 단어 : [{w}]!");

                if(turn != 0 && w[0] != lastTailChar)
                    throw new Exception($"이어지지않는 단어 : [{w}]!");

                if(hashSet.Contains(w))
                    throw new Exception($"중복 단어 : [{w}]!");
                
                hashSet.Add(w);
                lastTailChar = w[w.Length - 1];
            }
        }
        catch(Exception e)
        {
            System.Console.WriteLine(e.Message);
            return new int[2]{player, turn / n + 1};
        }
        
        return new int[2]{0, 0};
    }
}