#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/local_lim.h>
main()
{
	pthread_attr_t tattr;
	pthread_t tid;
	int ret;
	void *stackbase;
	int size = PTHREAD_STACK_MIN + PTHREAD_STACK_MIN;
	size_t size1;
	stackbase = (void *)malloc(size);
	ret = pthread_attr_init(&tattr);
	ret = pthread_attr_getstacksize(&tattr, &size1);
	printf("\n Default Stack Size %u :",size1);
	printf("\nThread Minimum Stack Size %u :\n",PTHREAD_STACK_MIN);	
	ret = pthread_attr_setstacksize(&tattr,size);
	ret = pthread_attr_getstacksize(&tattr, &size1);
	printf("\nUser Stack Size %u :\n",size1);
}
	
