#include<stdio.h>
#include<string.h>
int main()
{
	char *s;
	char buf[6] = "Linux";
	memset(buf,'#',2);
	printf("%s\n",buf);
	//bzero(buf+2,1);
	//printf("%s\n",buf);
	char *x;
        x = memchr(buf,'x',5);
	printf("%c\n",*x);
	char buf1[6];
	memmove(buf1, buf, 6);
	printf("%s\n",buf1);
}
