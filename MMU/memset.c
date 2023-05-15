#include<stdio.h>
#include<string.h>

int main()
{
	const char str[] = "linuxkernel.com";
	const char ch = '#';
	char *ret;
	printf("String before set/initialization is %s \n",str);
	ret = memchr(str,ch,strlen(str)-1);
	printf("String after set is %s \n",ret+1);
	return 0;
}
