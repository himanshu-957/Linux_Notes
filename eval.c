#include<stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x,y;
	int *a, *b;
	*a = 10;
	printf("*a = %d\n",*a);
	x = 10;
	y = 20;
	printf("Before swapping\n %d %d\n",x,y);
	swap(&x, &y);
	printf("After swapping\n %d %d\n",x,y);
	return 0;
}
