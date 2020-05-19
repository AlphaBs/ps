//5622

using System;

class Program
{
	public static void Main(string[] args)
	{
		var input = Console.ReadLine().ToCharArray();
		int result = 0;
		
		int[] c = new int[] { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
		
		foreach(var item in input)
		{
			var index = item - 65;
			result += c[index] + 1;
		}
		
		Console.Write(result);
	}
}
