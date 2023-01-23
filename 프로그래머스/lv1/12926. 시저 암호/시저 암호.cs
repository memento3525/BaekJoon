using System.Text;

public class Solution {
    public string solution(string s, int n) {
        
        var sb = new StringBuilder();
        
        for(int i = 0; i < s.Length; i++)
        {
            char c = s[i];
            if(c == ' ')
            {
                sb.Append(c);
                continue;
            }
            
            int ascii = (int)c + n;
            if((char.IsLower(c) && (ascii > (int)'z'))
              || (char.IsUpper(c) && (ascii > (int)'Z')))
            {
                ascii -= 26;
            }
            
            sb.Append((char)ascii);
        }
               
        return sb.ToString();
    }
}