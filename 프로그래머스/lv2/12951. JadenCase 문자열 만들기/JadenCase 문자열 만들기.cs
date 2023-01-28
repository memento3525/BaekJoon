using System.Text;

public class Solution {
    public string solution(string s) {
        
        var sb = new StringBuilder();
        bool isFirst = true;
        for(int i = 0; i < s.Length; i++)
        {
            char c = s[i];
            
            if(c == ' ')
            {
                isFirst = true;
            }
            else if(isFirst)
            {
                c = char.ToUpper(c);
                isFirst = false;
            }
            else
            {
                c = char.ToLower(c);
            }
            
            sb.Append(c);
        }
        
        return sb.ToString();
    }
}