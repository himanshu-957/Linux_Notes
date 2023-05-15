#include<unistd.h>
#include<stdio.h>

main()
{
        const int size = 4096;
        char* memory = malloc(size);
        mlock(memory, size);
	printf("Memory locked\n");
	for(size_t i = 0; i < size; i++)
                memory[i] = '0';
        printf("Allocated memory initialized with: %s\n", memory);
        munlock(memory, size);
	printf("Unlcoked memory\n");
}

