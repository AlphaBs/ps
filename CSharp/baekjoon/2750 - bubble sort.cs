//2750 - bubble sort (버블 정렬)

using System;

class Program
{
	public static void Main(string[] args)
	{
		//입력

		var count = int.Parse(Console.ReadLine());
		
		int[] arr = new int[count];
		
		for (int p = 0; p < count; p++)
		{
			arr[p] = int.Parse(Console.ReadLine());
		}
		
		//정렬
		for (int i = 0; i < count -  1; i++)
		{
			for (int j = 0; j < count - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int k = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = k;
					
				}
			}
		}
		
		//출력
		Console.Write(string.Join("\n", arr));
	}
}