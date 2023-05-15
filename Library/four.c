#include<stdio.h>
#include"file.h"
#include"add.c"
#include"sub.c"
void main()
{
	int min = 10;
 printf("Hello All\n");
 printf("Sum is: %d\n", add(10,5)); 
 printf("Sum is: %d\n", sub(10,5));
}
