public class Solution {
    public string solution(string s) {
        bool isEven = s.Length % 2 == 0;
        
        if(isEven)
            return s.Substring(s.Length / 2 - 1, 2);
        else
            return s.Substring((s.Length - 1) / 2, 1);
    }
}