using System.Linq;

public class Solution {
    public bool solution(string s) {
        
        if(s.Length!= 4 && s.Length != 6)
            return false;
        
        return !s.Any(e => !char.IsNumber(e));
    }
}