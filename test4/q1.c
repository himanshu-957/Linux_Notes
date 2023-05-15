#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
        int iFd, oFd, openFlags;
        mode_t filePerms;
        ssize_t count;
        char buf[1000];

        iFd = open(argv[1], O_RDWR,0777);
        if(iFd == -1)
        {
                printf("Error while Opening input Error\n");
                return;
        }

        oFd = open(argv[2], O_RDWR | O_CREAT, 0777);
        if(oFd == -1)
        {
                printf("Error while Opening output file\n");
                return;
        }
	int ret = write(iFd, "I am Himanshu Jadon", 19);
	printf("Count from source file is: %d\n",ret);
	lseek(iFd,0,SEEK_SET);

        while((count = read(iFd, buf, 1000)) > 0)
        {
                if(write(oFd, buf, count) != count)
                {
                        printf("Error Occured while writting\n");
                        return;
                }
                printf("Count from destination file after copying : %d\n",count);
        }
        if(count == -1 || close(iFd) == -1 || close(oFd == -1))
        {
                printf("Error in closing files\n");
                return;
        }
	return 0;
}
