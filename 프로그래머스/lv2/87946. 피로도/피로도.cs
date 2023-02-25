using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int k, int[,] dungeons) {
        
        int answer = 0;
        
        int size = dungeons.GetLength(0); 
        int[] arr = Enumerable.Range(0, size).ToArray();
        var permList = new List<int[]>();
        
        Perm(arr, 0, size, size, permList);
        
        for(int i = 0; i < permList.Count; i++)
        {
            int fatigue = k;
            int completeDungeon = 0;
            int[] indexArray = permList[i];
            
            for(int j = 0; j < size; j++)
            {
                int dungeonIndex = indexArray[j];
                if(fatigue < dungeons[dungeonIndex, 0])
                    break;
                
                fatigue -= dungeons[dungeonIndex, 1];
                completeDungeon++;
            }
            
            if(answer < completeDungeon)
                answer = completeDungeon;
        }
        
        return answer;
    }
    
    private static void Perm(int[] arr, int depth, int n, int k, List<int[]> result)
    {
        if(depth == k) // 끝. 출력
        {
            result.Add(arr.Clone() as int[]);
            return;
        }
        
        for(int i = depth; i < n; i++)
        {
            Swap(arr, i, depth);
            Perm(arr, depth + 1, n, k, result);
            Swap(arr, i, depth);
        }
    }
    
    private static void Swap(int[] arr, int i, int j)
    {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
    }
}