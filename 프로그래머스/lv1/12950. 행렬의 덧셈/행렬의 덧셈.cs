public class Solution {
    public int[,] solution(int[,] arr1, int[,] arr2) {
        
        int length0 = arr1.GetLength(0);
        int length1 = arr1.GetLength(1);
        int[,] answer = new int[length0, length1];
        
        for(int x = 0; x < length0; x++)
        {
            for(int y = 0; y < length1; y++)
                answer[x, y] = arr1[x, y] + arr2[x, y];
        }
        
        return answer;
    }
}