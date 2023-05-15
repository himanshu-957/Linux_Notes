#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int ret, i, cnt = 0;
	errno = 0;
	ret = nice(19);
	if(ret == -1 && errno != 0)
		perror("nice");
	else
		printf("nice value is now %d\n", ret);
	while(1)
	{
		printf("Process with nice value %d count = %d\n", ret,cnt);
		for(i = 0 ;i < 10000000; i++);
		cnt++;
	}
}
