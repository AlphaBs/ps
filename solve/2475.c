#include <stdio.h>

int main(void)
{
	int v1,v2,v3,v4,v5;
	scanf("%d %d %d %d %d", &v1, &v2, &v3, &v4, &v5);

	int zSum = v1*v1 + v2*v2 + v3*v3 + v4*v4 + v5*v5;
	int validNum = zSum % 10;
	printf("%d", validNum);
	return 0;
}
