using System.Linq;

public class Solution {
    public string solution(string phone_number) {
        var array = phone_number.Select((e, index) => index >= (phone_number.Length - 4) ? e : '*')
                                .ToArray();
        return new string(array);
    }
}