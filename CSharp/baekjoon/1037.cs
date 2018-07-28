//1037

using System;

class Program
{
	public static void Main(string[] args)
	{
		var l = int.Parse(Console.ReadLine());
		var a = Console.ReadLine().Split(' ');
		
		int min = int.Parse(a[0]);
		int max = min;
		
		for(int i = 1; i < l; i++)
		{
			//Console.WriteLine("{0} {1}", l, i);
			var v = int.Parse(a[i]);
			if (min > v)
				min = v;
			if (max < v)
				max = v;
		}
		
		Console.Write(min * max);
	}
}