#include<stdio.h>
int main()
{
	printf("First\n");
	fork();

	fork();

	fork();
	printf("Second\n");
	while(1);
	return 0;
}
