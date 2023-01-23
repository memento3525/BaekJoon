using System;
using System.Text;

public class Solution
{
    static void Main()
    {
        string y = Console.ReadLine();

        int[] count = new int[6] { 1, 1, 2, 2, 2, 8 };
        string[] splited = y.Split();

        for (int i = 0; i< splited.Length; i++)
        {
            int num = Convert.ToInt32(splited[i]);
            count[i] -= num;
        }

        var sb = new StringBuilder();

        for (int i = 0; i < count.Length; i++)
        {
            if(i == count.Length - 1)
                sb.Append($"{count[i]}");
            else
                sb.Append($"{count[i]} ");
        }

        Console.WriteLine(sb.ToString());
    }
}