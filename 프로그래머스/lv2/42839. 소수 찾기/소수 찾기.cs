using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(string numbers) 
    {
        var hashSet = new HashSet<int>();
        
        for(int i = 1; i <= numbers.Length; ++i)
            DFS(numbers.ToCharArray(), 0, i, hashSet);
        
        int answer = 0;
        foreach(int num in hashSet)
        {
            if(IsPrimer(num))
                ++answer;
        }
        return answer;
    }
    
    private void DFS(char[] arr, int depth, int length, HashSet<int> hashSet)
    {
        if(depth == length)
        {
            string result = new string(arr.Take(length).ToArray());
            hashSet.Add(int.Parse(result));
            return;
        }
        
        for(int i = depth; i < arr.Length; i++)
        {
            var copyArr = arr.Clone() as char[];
            Swap(copyArr, i, depth);
            DFS(copyArr, depth + 1, length, hashSet);
        }
    }
    
    private static void Swap(char[] arr, int x, int y)
    {
        char temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
    
    private bool IsPrimer(int n)
    {
        if(n <= 1) return false;
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
                return false;
        }
        return true;
    }
}