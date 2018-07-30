//2750 - selection sort 선택정렬

using System;

class Program
{
	public static void Main()
	{
		//입력
		var count = int.Parse(Console.ReadLine());
		int[] arr = new int[count];
		
		for (int p = 0; p < count; p++)
		{
			arr[p] = int.Parse(Console.ReadLine());
		}
		
		//정렬
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

		//출력
		for (int k = 0; k < arr.Length; k++)
		{
			Console.WriteLine(arr[k]);
		}
	}
}