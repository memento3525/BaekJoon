using System.Linq;

public class Solution {
    public string[] solution(string[] strings, int n) {
        return strings.OrderBy(e => e[n])
               .ThenBy(e => e).ToArray();
    }
}