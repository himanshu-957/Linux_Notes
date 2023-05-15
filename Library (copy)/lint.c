#include<stdio.h>
int main()
{
	int x = 10;
	switch(x)
	{
		case 1:
			printf("result = one\n");
			break;
		case 2:
			printf("result = two\n");

		default:
			printf("INVALID\n");
			break;
	}
	return 0;
}
