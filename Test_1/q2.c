#include<stdio.h>
#include<sys/stat.h>

int main()
{
        struct stat st;
        stat("linux.txt",&st);
	printf("ls -l like information using stat structure\n");
        printf("Size = %lu\n", st.st_size);
        printf("Inode = %lu\n", st.st_ino);
        printf("Block = %lu\n",st.st_blksize);
        return 0;
}

