using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int n) 
    {
        int answer = 0;

        // 한 줄에 한개의 퀸만 들어갈 수 있다.
        // 0 ~ n - 1 로 만들 수 있는 순열을 만들고 체크.
        int[] arr = Enumerable.Range(0, n).ToArray();
        Perm(arr, 0, n, ref answer);

        return answer;
    }

    private void Perm(int[] arr, int depth, int n, ref int answer)
    {
        if(depth == n)
        {
            ++answer;
            return;
        }

        for(int i = depth; i < n; ++i)
        {
            Swap(arr, i, depth);
            
            if(IsValid(arr, depth))
                Perm(arr, depth + 1, n, ref answer);
            
            Swap(arr, i, depth);
        }
    }

    private void Swap(int[] arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    // 가로가 k만큼 차이날 때 y도 k만큼 차이나면 대각선이니 제외한다.
    // 아직 depth까지만 채워져 있기때문에 가로줄 기준 depth까지만 체크해도된다.
    private bool IsValid(int[] arr, int depth)
    {
        for(int x = 0; x < depth; ++x)
        {
            if(Math.Abs(x - depth) == Math.Abs(arr[x] - arr[depth]))
                return false;
        }
        return true;
    }
}