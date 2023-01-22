using System;

public class Solution {
    public int solution(string A, string B) {
        
        char[] A_Array = A.ToCharArray();
        char[] B_Array = B.ToCharArray();
        
        int length = A.Length;
        for(int offset = 0;  offset < length; offset++)
        {
            bool isMatch = true;
            for(int index = 0; index < length; index++)
            {
                int circularIndex = (index + offset) % length;
                if(A_Array[index] != B_Array[circularIndex])
                {
                    isMatch = false;
                    break;
                }
            }
            
            if(isMatch)
                return offset;
        }
        
        return -1;
    }
}