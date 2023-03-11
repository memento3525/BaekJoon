using System;

public class Solution {
    public int[] solution(int[,] arr) 
    {
        int[] answer = new int[2];
        GetChildren(arr, 0, 0, arr.GetLength(0), answer);
        return answer;
    }
    
    private void GetChildren(int[,] arr, int y, int x, int size, int[] answer)
    {
        if(CheckIfZip(arr, y, x, size)) // 마지막에 자기자신만 남으면 어차피 모든 노드가 압축이 가능하다
        {
            if(arr[y, x] == 1) answer[1]++;
            else answer[0]++;
            return;
        }
        
        int half = size / 2;
        GetChildren(arr, y, x, half, answer);
        GetChildren(arr, y + half, x, half, answer);
        GetChildren(arr, y, x + half, half, answer);
        GetChildren(arr, y + half, x + half, half, answer);
    }
    
    public bool CheckIfZip(int[,] arr, int y, int x, int size)
    {
        int value = arr[y, x];
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                if(arr[i + y, j + x] != value)
                    return false;
            }
        }
        return true;
    }
}