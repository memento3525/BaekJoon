using System;
using System.Text;

public class Example
{
    public static void Main()
    {
        Console.Clear();
        String[] s = Console.ReadLine().Split(' ');

        int n = Int32.Parse(s[0]);
        int m = Int32.Parse(s[1]);

        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < n; i++)
            sb.Append("*");
        
        for(int i = 0; i < m; i++)
            Console.WriteLine(sb.ToString());
    }
}