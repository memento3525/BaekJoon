using System;
using System.Text;

public class Example
{
    public static void Main()
    {
        Console.Clear();
        String s = Console.ReadLine();

        int offset = 'a' - 'A';
        var sb = new StringBuilder();
        foreach(char c in s)
        {
            if(c > 'Z') // isLower
                sb.Append((char)(c - offset));
            else // isUpper
                sb.Append((char)(c + offset));
        }
        
        Console.WriteLine(sb);
    }
}