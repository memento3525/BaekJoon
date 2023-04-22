using System;
using System.Text;

public class Example
{
    public static void Main()
    {
        Console.Clear();
        String[] input = Console.ReadLine().Split(' ');

        String str = input[0];
        int n = Int32.Parse(input[1]);
        
        var sb = new StringBuilder();
        for(int i = 0; i < n; ++i)
            sb.Append(str);
        
        Console.WriteLine(sb.ToString());
    }
}