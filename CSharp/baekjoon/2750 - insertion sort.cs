//2750 - insertion sort 삽입정렬

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
		for (int i = 1; i < count; i++)
		{
			int key = arr[i];
			for (int j = i - 1; j >= 0; j--)
			{
				if (key > arr[j])
					break;
				arr[j + 1] = arr[j];
				arr[j] = key;
			}
		}
		
		//출력
		Console.Write(string.Join("\n", arr));
	}
	
	static int[] insert(int[] arr, int a, int b)
	{
		int[] nrr = new int[arr.Length];
		bool issuc = false;
		for(int i = 0; i < arr.Length; i++)
		{
			if (i == a)
			{
				nrr[i] = arr[b];
				issuc = true;
			}
			else
			{
				if (issuc)
				{
					if (i == b) issuc = false;
					nrr[i] = arr[i - 1];
				}
				else
					nrr[i] = arr[i];
			}
		}

		return nrr;
	}
}