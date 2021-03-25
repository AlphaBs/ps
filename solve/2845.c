#include <stdio.h>

int main(void)
{
	int peoplePerPlace;
	int placeSize;
	scanf("%d %d", &peoplePerPlace, &placeSize);

	int peopleNumber = peoplePerPlace * placeSize;

	int people1, people2, people3, people4, people5;
	scanf("%d %d %d %d %d", 
			&people1, &people2, &people3, &people4, &people5);

	int b1 = people1 - peopleNumber;
	int b2 = people2 - peopleNumber;
	int b3 = people3 - peopleNumber;
	int b4 = people4 - peopleNumber;
	int b5 = people5 - peopleNumber;
	printf("%d %d %d %d %d", b1, b2, b3, b4, b5);
	return 0;
}
