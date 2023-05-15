#include<stdio.h>
#include<stdlib.h>
void buggy()
{
	int *intptr;
	int i;
	intptr = (int *)malloc(sizeof(int)*5);

	for(i = 0;i<3;i++)
	{
		* intptr = 100;
		printf("value at ptr intptr = %d\n",(*intptr));
		intptr--;
		// printf("value at ptr intptr = %d\n",(*intptr));
	}
}

int main()
{
	buggy();
	return 0;
}
