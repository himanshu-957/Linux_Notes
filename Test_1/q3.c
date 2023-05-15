#include<stdio.h>
#include<unistd.h>

int main()
{
        void* c1 = sbrk(0);
        printf("program before sbrk and brk address: %p\n", c1);

        void* c2 = sbrk(4);
        printf("program after sbrk address: %p\n",c2);

	brk(c1+2);
	void* c3 = sbrk(0);
        printf("program brk address: %p\n",c3);
}
