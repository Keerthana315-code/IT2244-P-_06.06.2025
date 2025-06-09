#include<studio.h>
#include<stdlib.h>
#include<unistd.h>

#define MSGIZE 16

char* msg1 = "Hello, world! #1";
char* msg2 = "Hello, world! #2";
char* msg3 = "Hello, world! #3";

int main()
{
	char inbuf[MSGIZE];
	int p[2],i;
	
	if(pipe(p)<0)
		exit(1);
	
	/* continued*/
	/* write pipe*/
	
	write (p[1], msg1, MSGIZE);
	write (p[1], msg2, MSGIZE);
	write (p[1], msg3, MSGIZE);
	
	for(i=0;i<3;i++)
	{
		/*read pipe*/
		read(p[0],inbuf,MSGIZE);
		printf("%s\n",inbuf);
	}
	return 0;
}