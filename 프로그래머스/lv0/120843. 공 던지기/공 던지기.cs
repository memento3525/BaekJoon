using System;
using System.Linq;

public class Solution {
    public int solution(int[] numbers, int k) {
        
        int size = numbers.Length;
        int index = ((k - 1) * 2) % size;
        return numbers[index];
    }
}