//2750

using System;

class Program
{
	public static void Main()
	{
		var count = int.Parse(Console.ReadLine());
		int[] arr = new int[count];
		
		for (int p = 0; p < count; p++)
		{
			arr[p] = int.Parse(Console.ReadLine());
		}
		
		for (int i = 0; i < count; i++)
		{
			int min = arr[i];
			int index = i;
			for (int j = i + 1; j < count; j++)
			{
				if (min > arr[j])
				{
					min = arr[j];
					index = j;
				}
			}
			
			int t = arr[i];
			arr[i] = arr[index];
			arr[index] = t;
		}

		for (int k = 0; k < arr.Length; k++)
		{
			Console.WriteLine(arr[k]);
		}
	}
}