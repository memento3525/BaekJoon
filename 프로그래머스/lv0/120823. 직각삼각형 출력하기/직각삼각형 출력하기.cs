using System;
using System.Text;

public class Example
{
    public static void Main()
    {
        String[] s;
        StringBuilder sb = new StringBuilder();

        Console.Clear();
        s = Console.ReadLine().Split(' ');

        int n = Int32.Parse(s[0]);
        for(int i = 0; i < n; i++)
        {
            sb.Append("*");
            Console.WriteLine(sb);
        }
    }
}