#include <stdio.h>
#include <stdlib.h>

int copyArray(int source[], int sourceStartIndex, int destination[], int destinationStartIndex, int count)
{
	for (int i = 0; i < count; i++)
	{
		int desIdx = destinationStartIndex + i;
		int socIdx = sourceStartIndex + i;
		destination[desIdx] = source[socIdx];
	}

	return count;
}

void merge(int orgArr[], int leftIndex, int leftLength, int rightIndex, int rightLength)
{
	int resultCount = leftLength + rightLength;
	int*result = (int*) malloc(sizeof(int) * resultCount);
	int resultIndex = 0;

	if (result == NULL)
	{
		printf("failed to malloc");
		return;
	}

	int cLeft = 0;
	int cRight = 0;

	while (cLeft < leftLength && cRight < rightLength)
	{
		int leftRealIndex = leftIndex + cLeft;
		int rightRealIndex = rightIndex + cRight;
		int leftValue = orgArr[leftRealIndex];
		int rightValue = orgArr[rightRealIndex];

		if (leftValue < rightValue)
		{
			result[resultIndex++] = leftValue;
			if (cLeft == leftLength - 1)
			{
				copyArray(orgArr, rightRealIndex, result, resultIndex, rightLength - cRight);
				break;
			}
			cLeft++;
		}
		else
		{
			result[resultIndex++] = rightValue;
			if (cRight == rightLength - 1)
			{
				copyArray(orgArr, leftRealIndex, result, resultIndex, leftLength - cLeft);
				break;
			}
			cRight++;
		}
	}

	copyArray(result, 0, orgArr, leftIndex, resultCount);
	free(result);

	//printf("=========================\n");
	//for (int i = 0; i < 20; i++)
	//{
	//	printf("%d ", orgArr[i]);
	//}
	//printf("\n");
}

void sort(int inputArr[], int index, int size)
{
	if (size < 2)
		return inputArr;

	int mid = size / 2;

	int leftStart = index;
	int leftLength = mid;
	int rightStart = index + leftLength;
	int rightLength = size - mid;

	if (leftLength > 1)
		sort(inputArr, leftStart, leftLength);
	if (rightLength > 1)
		sort(inputArr, rightStart, rightLength);

	merge(inputArr, leftStart, leftLength, rightStart, rightLength);
}

int main()
{
	//int count2 = 5;
	//int inputArr2[5] = { 38,70,6,18,44 };
	//merge(inputArr2, 0, 2, 2, 3);

	// input
	int count = 0;
	scanf("%d", &count);

	int* inputArr = (int*) malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &inputArr[i]);
	}

	// sort
	sort(inputArr, 0, count);

	// output
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", inputArr[i]);
	}
}