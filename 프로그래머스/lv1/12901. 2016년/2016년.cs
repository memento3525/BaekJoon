using System;

public class Solution {
    public string solution(int a, int b) {
        
        string[] strArray = new string[7]{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        
        DateTime time = new DateTime(2016, a, b);
        int index = (int)time.DayOfWeek;
        return strArray[index];
    }
}