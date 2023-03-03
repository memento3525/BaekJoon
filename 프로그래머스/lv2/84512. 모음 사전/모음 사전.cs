using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(string word) {
        
        var list = new List<string>();
        var arr = new char[5]{'A', 'E', 'I', 'O', 'U'};
        for(int i = 1; i < arr.Length + 1; i++)
            Traverse(arr, "", 0, i, list);
        
        list.Sort();
        return list.FindIndex(s => s == word) + 1;
    }
    
    private void Traverse(char[] arr, string str, int depth, int length, List<string> list)
    {
        if(depth == length)
        {
            list.Add(str);
            return;
        }
        
        for(int i = 0; i < arr.Length; i++)
            Traverse(arr, str + arr[i], depth + 1, length, list);
    }
    
    private void Swap(char[] arr, int x, int y)
    {
        var temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
}