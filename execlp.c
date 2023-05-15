int main()
{
	printf("I am going to exec an ls process in current process\n");
	execlp("ls","ls",0);
	printf("I execed 'ls' process\n");
}
