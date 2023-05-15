#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void *pro(void)
{
	sleep(2);
	return 0;
}
int main()
{
	pthread_attr_t myattr;
	pthread_t mythrd;
	void *addr,*addr1;
	size_t siz;
	size_t mysiz = 0x500000;
	pthread_attr_init(&myattr);
	pthread_attr_getstacksize(&myattr,&siz);
	pthread_attr_getstackaddr(&myattr,&addr);
	printf("Default size = %d and addr = %08x\n",siz,addr);
	addr1 = (void*)malloc(mysiz);
	//siz = 0x300000;
	pthread_attr_setstack(&myattr,addr1,mysiz);
	pthread_create(&mythrd, NULL, pro, NULL);
	pthread_attr_getstack(&myattr,&addr1,&siz);
	printf("After setting size = %d and addr = %08x\n",siz,addr1);
	return 0;
}
