#include<stdio.h>
void main()
{
 int num, temp, rem, new = 0;
 printf("Enter the number: ");
 scanf("%d",&num);
 while(num/10 != 0 || num == 7)
 {
  temp = num;
  while(temp > 0)
  {
   rem = temp%10;
   temp /= 10;
   new += rem*rem;

  }
  printf("%d\n",new);
  num = new;
  new = 0;
 }
printf("%d\n",num);
}
