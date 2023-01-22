using System;

public class Solution {
    public int solution(int[] array) {

        int middleIndex = array.Length / 2;
        Array.Sort(array);
        
        return array[middleIndex];
    }
}