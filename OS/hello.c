#include <stdio.h>

int main(int  argc, char** argv)
{
	char s[1024];
	
	//fscanf(stdin, "%s",s);

	//fprintf(stdout, "Hello %s\n", s);
	//fprintf(stderr, "(debug)\n");

	if(*argv[0])
		printf("%s\n", argv[0]);
}
