using System;
using System.Collections.Generic;
using System.IO;

class Day6
{
    static int Day6Part1(List<List<string>> columns)
    {
        int res = 0;

        var col = columns[2];
        bool add = true;
        if (col[4] == "*") add = false;
        for(int i = 0; i<4; i++)
        {
            Console.Write(col[i] + " ");
            if (add)
            {
                res += int.Parse(col[i]);
            }
            else
            {
                res *= int.Parse(col[i]);
            }
        }
        Console.WriteLine();
        

        return res;
    }

    static void Main(string[] args)
    {
        List<List<string>> columns = new List<List<string>>();
        string[] lines = File.ReadAllLines("./input.txt");

        foreach (string line in lines)
        {
            if (string.IsNullOrEmpty(line))
            {
                continue;
            }
            string[] values = line.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);

            for (int colIndex = 0; colIndex < values.Length; colIndex++)
            {
                while (colIndex >= columns.Count)
                {
                    columns.Add(new List<string>());
                }

                // Add value to the appropriate column
                columns[colIndex].Add(values[colIndex]);
            }
        }

        // Print column info for debugging
        Console.WriteLine($"Number of columns: {columns.Count}");
        if (columns.Count > 0)
        {
            Console.WriteLine($"Number of rows: {columns[0].Count}");
        }

        int result = Day6Part1(columns);
        Console.WriteLine($"Result: {result}");
    }
}
